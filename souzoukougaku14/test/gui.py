import sys
from PyQt5 import QtCore
from PyQt5.QtWidgets import QApplication, QMainWindow
from graph_ui import Ui_MainWindow  # pyuic5 で生成されたクラスをインポート
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure
import numpy as np  # 数学計算用
from scipy.interpolate import interp1d

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
from geometry_msgs.msg import Twist,Pose
from cat_messages.msg import Vel


# カスタム PlotCanvas クラス: Matplotlib を埋め込む
class PlotCanvas(FigureCanvas):
    def __init__(self, parent=None):
        self.fig = Figure()
        self.axes = self.fig.add_subplot(111)
        super().__init__(self.fig)
        self.setParent(parent)
        
        #path 1to2
        self.path_1to2_t = np.array([0,1,2,3])
        self.path_1to2_x = np.array([0,1000,1000,0])
        self.path_1to2_y = np.array([0,0,1000,1000])
        self.f_CS_y_path_1to2 = interp1d(self.path_1to2_t, self.path_1to2_y, kind='linear')
        self.f_CS_x_path_1to2 = interp1d(self.path_1to2_t, self.path_1to2_x, kind='linear')
        self.xnew_path_1to2 =np.linspace(0, 3, num=10)

    def plot(self, x, y, yaw):
        """
        x, y: 矢印の起点 (リストまたは単一の数値)
        yaw: 矢印の向き (リストまたは単一の数値, ラジアン単位)
        """
        self.axes.cla()  # プロットをクリア

        # 入力をリスト形式に変換
        if not isinstance(x, (list, np.ndarray)):
            x = [x]
        if not isinstance(y, (list, np.ndarray)):
            y = [y]
        if not isinstance(yaw, (list, np.ndarray)):
            yaw = [yaw]

        # 矢印の方向を計算 (yaw を元にベクトルを作成)
        u = np.cos(yaw)  # x方向のベクトル成分
        v = np.sin(yaw)  # y方向のベクトル成分

        
        # 経路をプロット
        path_x = self.f_CS_x_path_1to2(self.path_1to2_t)
        path_y = self.f_CS_y_path_1to2(self.path_1to2_t)
        self.axes.plot(path_x, path_y, 'r--', label="Path 1 to 2")  # 経路を赤の破線で描画
        cx=self.f_CS_x_path_1to2(self.xnew_path_1to2),
        cy=self.f_CS_y_path_1to2(self.xnew_path_1to2),
        self.axes.plot(cx, cy,'o')

        # 矢印を描画
        self.axes.quiver(x, y, u, v, angles='xy', scale_units='xy', scale=0.01, color='blue')
        self.axes.set_xlim(-20,1200)
        self.axes.set_ylim(-20,1200)
        self.axes.set_title("Arrows at Specified Points")

        self.draw()

    def clear(self):
        self.axes.cla()  # プロットをクリア
        self.draw()


# メインウィンドウ
class GraphApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.ui = Ui_MainWindow()  # 生成されたクラスをインスタンス化
        self.ui.setupUi(self)  # メインウィンドウにセットアップ
        
        # QtTimerのインスタンスを生成してros_spin関数をバインド
        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self.ros_spin)
        
         # 処理周期の設定
        self.update_period = 10
        self.timer.start(self.update_period)
        
        # ノードの初期化
        rclpy.init(args=None)
        self.node = Node("gui_node")
        self.node.create_timer(0.1,self.timer_callback)
        self.node.create_subscription(
            Pose,"pose",self.pose_cb,10
        )
        self.pose =[0.0,0.0,0.0]
        self.node.create_subscription(
            Vel,'vel',self.vel_callback,10
        )
        self.pub = self.node.create_publisher(
            Int32,'/topic',10
        )
        self.count =0

        # PlotCanvas を plotWidget に埋め込む
        self.plotCanvas = PlotCanvas(self.ui.plotWiget)
        layout = self.ui.plotWiget.layout()
        if layout is None:
            from PyQt5.QtWidgets import QVBoxLayout
            layout = QVBoxLayout()
            self.ui.plotWiget.setLayout(layout)
        layout.addWidget(self.plotCanvas)

        # ボタンにイベントを接続
        #self.ui.emergency.clicked.connect(self.plotCanvas.plot())
        self.ui.emergency.clicked.connect(self.button_update)
        
    def vel_callback(self,msg):
        self.ui.vel_x.setText(str(msg.vel_x))
        self.ui.vel_y.setText(str(msg.vel_y))
        self.ui.vel_yaw.setText(str(msg.vel_yaw))
        
        self.ui.vel_wheel_right.setText(str(msg.vel_wheel_right))
        self.ui.vel_wheel_left.setText(str(msg.vel_wheel_left))
        
        
        
    def pose_cb(self,msg):
        self.pose[0] = msg.position.x
        self.pose[1] = msg.position.y
        self.pose[2] = msg.orientation.z
        self.ui.pose_x.setText(str(self.pose[0]))
        self.ui.pose_y.setText(str(self.pose[1]))
        self.ui.pose_yaw.setText(str(self.pose[2]))
        
    def timer_callback(self):
        self.plotCanvas.plot(x=self.pose[0],y=self.pose[1],yaw=self.pose[2])
    
    def ros_spin(self):
        rclpy.spin_once(self.node,timeout_sec=0.01)
        self.show()
        self.timer.start(self.update_period)

        
    def pub_int32(self,num: int):
        msg = Int32()
        msg.data=num
        self.pub.publish(msg)

    def button_update(self):
        self.count +=1
        self.pub_int32(self.count)
        print(f'{self.count}回目のボタンが押されました\n')
        self.plotCanvas.plot(x=1,y=1,yaw=0)

def main():
    app = QApplication(sys.argv)
    window = GraphApp()
    window.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
