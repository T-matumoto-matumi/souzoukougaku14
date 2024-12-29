import cv2
from cv_bridge import CvBridge,CvBridgeError
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image,CameraInfo
import yaml
from std_msgs.msg import Header
from builtin_interfaces.msg import Time

def load_camera_info(yaml_file):
    with open(yaml_file, 'r') as file:
        data = yaml.safe_load(file)
    
    camera_info = CameraInfo()

    # 基本情報
    camera_info.width = data['image_width']
    camera_info.height = data['image_height']
    camera_info.distortion_model = data['distortion_model']
    # カメラ行列
    camera_info.k = data['camera_matrix']['data']
    
    # 歪み係数
    camera_info.d = data['distortion_coefficients']['data']
    
    # レクティフィケーション行列
    camera_info.r = data['rectification_matrix']['data']
    
    # 射影行列
    camera_info.p = data['projection_matrix']['data']
    
    camera_info.header.frame_id = data['camera_name']

    
    return camera_info

class CamNode(Node):
    def __init__(self,yaml_file):
        super().__init__("cam_node")
        self.image_pub = self.create_publisher(
            Image,"image_raw",10
        )
        self.caminfo_pub = self.create_publisher(
            CameraInfo, 'camera_info', 10
        )
        self.camera_info = load_camera_info(yaml_file)
        self.br = CvBridge()
        timer_period =0.01
        self.timer = self.create_timer(timer_period,self.timer_callback)
        self.cap = cv2.VideoCapture(0)
        self.get_logger().info("OpenCV version")
        self.get_logger().info(cv2.__version__)
        
    def timer_callback(self):
        
        self.caminfo_pub.publish(self.camera_info)
        if(self.cap.isOpened()):
            ret,frame = self.cap.read()
            if ret==True:
                try:
                    image_msg = self.br.cv2_to_imgmsg(frame,"bgr8")
                    self.image_pub.publish(image_msg)
                except CvBridgeError as e:
                    print(e)
                    
def main(args=None):
    rclpy.init(args=args)
    yaml_file = '/home/hamilton/souzou/souzoukougaku14/src/cat/config/ost.yaml'  
    node = CamNode(yaml_file)
    rclpy.spin(node)
    node.cap.release()
    cv2.destroyAllWindows()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
        
            
        