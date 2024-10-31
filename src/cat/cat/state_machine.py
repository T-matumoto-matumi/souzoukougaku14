import rclpy
from rclpy.node import Node
from cat_messages.msg import JoyCat
from enum import Enum
class MachineState(Enum):
    ManualMode=1
    AutoMode=2


class StateMachine(Node):
    def __init__(self):
        super().__init__("state_machine")
        self.joy_sub = self.create_subscription(
            JoyCat,"joy_cat",self.joy_callback,10
        )
        timer_period =0.01
        self.timer = self.create_timer(timer_period,self.timer_callback)
        self.MachineState = MachineState()
        self.MachineState = 1 #defult mamual mode
        self.joy_msg = JoyCat()
        
    def joy_callbak(self,msg):
        self.joy_msg = msg
        
    def timer_callback(self):
        if self.MachineState is MachineState.ManualMode:
            #kokoni manual mode kaku
            pass        
        elif self.MachineState is MachineState.AutoMode:
            #`kokoni auto mode kaku`
            
    