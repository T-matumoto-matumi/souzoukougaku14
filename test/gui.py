import sys
from PyQt5 import QtCore
from PyQt5.QtWidgets import QApplication, QMainWindow
from graph_ui import Ui_MainWindow  # pyuic5 で生成されたクラスをインポート
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure
import numpy as np  # 数学計算用

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32


# カスタム PlotCanvas クラス: Matplotlib を埋め込む
class PlotCanvas(FigureCanvas):
    def __init__(self, parent=None):
        self.fig = Figure()
        self.axes = self.fig.add_subplot(111)
        super().__init__(self.fig)
        self.setParent(parent)

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

        # 矢印を描画
        self.axes.quiver(x, y, u, v, angles='xy', scale_units='xy', scale=0.1, color='blue')
        self.axes.set_xlim(0,82)
        self.axes.set_ylim(0, 111)
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
        self.pub = self.node.create_publisher(
            Int32,'/topic',10
        )
        self.count =0

        # PlotCanvas を plotWidget に埋め込む
        self.plotCanvas = PlotCanvas(self.ui.plotWidget)
        layout = self.ui.plotWidget.layout()
        if layout is None:
            from PyQt5.QtWidgets import QVBoxLayout
            layout = QVBoxLayout()
            self.ui.plotWidget.setLayout(layout)
        layout.addWidget(self.plotCanvas)

        # ボタンにイベントを接続
        #self.ui.emergency.clicked.connect(self.plotCanvas.plot())
        self.ui.emergency.clicked.connect(self.button_update)
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
