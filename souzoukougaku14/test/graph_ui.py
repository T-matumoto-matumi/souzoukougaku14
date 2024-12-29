# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'graph_ui.ui'
#
# Created by: PyQt5 UI code generator 5.15.6
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1103, 842)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.emergency = QtWidgets.QPushButton(self.centralwidget)
        self.emergency.setGeometry(QtCore.QRect(330, 150, 201, 621))
        font = QtGui.QFont()
        font.setPointSize(24)
        self.emergency.setFont(font)
        self.emergency.setStyleSheet("background-color: rgb(255, 0, 0);")
        self.emergency.setObjectName("emergency")
        self.state_title = QtWidgets.QLabel(self.centralwidget)
        self.state_title.setGeometry(QtCore.QRect(20, 30, 481, 51))
        font = QtGui.QFont()
        font.setPointSize(22)
        self.state_title.setFont(font)
        self.state_title.setStyleSheet("\n"
"QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.state_title.setScaledContents(False)
        self.state_title.setAlignment(QtCore.Qt.AlignCenter)
        self.state_title.setObjectName("state_title")
        self.state = QtWidgets.QLabel(self.centralwidget)
        self.state.setGeometry(QtCore.QRect(20, 90, 481, 51))
        font = QtGui.QFont()
        font.setPointSize(22)
        self.state.setFont(font)
        self.state.setStyleSheet("\n"
"QLabel{\n"
"    border: 2px solid black;\n"
"    background-color: rgb(0, 255, 127);\n"
"}\n"
"")
        self.state.setScaledContents(False)
        self.state.setAlignment(QtCore.Qt.AlignCenter)
        self.state.setObjectName("state")
        self.plotWiget = QtWidgets.QWidget(self.centralwidget)
        self.plotWiget.setGeometry(QtCore.QRect(560, 29, 501, 741))
        self.plotWiget.setObjectName("plotWiget")
        self.widget = QtWidgets.QWidget(self.centralwidget)
        self.widget.setGeometry(QtCore.QRect(20, 150, 271, 611))
        self.widget.setObjectName("widget")
        self.verticalLayout_7 = QtWidgets.QVBoxLayout(self.widget)
        self.verticalLayout_7.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_7.setObjectName("verticalLayout_7")
        self.verticalLayout_4 = QtWidgets.QVBoxLayout()
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.pose_title = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setPointSize(24)
        self.pose_title.setFont(font)
        self.pose_title.setAcceptDrops(False)
        self.pose_title.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.pose_title.setAutoFillBackground(False)
        self.pose_title.setStyleSheet("QLabel{\n"
"    border: 2px solid brack;\n"
"    \n"
"}")
        self.pose_title.setScaledContents(False)
        self.pose_title.setAlignment(QtCore.Qt.AlignCenter)
        self.pose_title.setWordWrap(False)
        self.pose_title.setObjectName("pose_title")
        self.verticalLayout_4.addWidget(self.pose_title)
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label_x = QtWidgets.QLabel(self.widget)
        self.label_x.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.label_x.setObjectName("label_x")
        self.horizontalLayout.addWidget(self.label_x)
        self.pose_x = QtWidgets.QLabel(self.widget)
        self.pose_x.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.pose_x.setObjectName("pose_x")
        self.horizontalLayout.addWidget(self.pose_x)
        self.verticalLayout_2.addLayout(self.horizontalLayout)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.label_y = QtWidgets.QLabel(self.widget)
        self.label_y.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.label_y.setObjectName("label_y")
        self.horizontalLayout_2.addWidget(self.label_y)
        self.pose_y = QtWidgets.QLabel(self.widget)
        self.pose_y.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.pose_y.setObjectName("pose_y")
        self.horizontalLayout_2.addWidget(self.pose_y)
        self.verticalLayout_2.addLayout(self.horizontalLayout_2)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_yaw = QtWidgets.QLabel(self.widget)
        self.label_yaw.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.label_yaw.setObjectName("label_yaw")
        self.horizontalLayout_3.addWidget(self.label_yaw)
        self.pose_yaw = QtWidgets.QLabel(self.widget)
        self.pose_yaw.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.pose_yaw.setObjectName("pose_yaw")
        self.horizontalLayout_3.addWidget(self.pose_yaw)
        self.verticalLayout_2.addLayout(self.horizontalLayout_3)
        self.verticalLayout_4.addLayout(self.verticalLayout_2)
        self.verticalLayout_7.addLayout(self.verticalLayout_4)
        self.verticalLayout_5 = QtWidgets.QVBoxLayout()
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        self.vel_title = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setPointSize(24)
        self.vel_title.setFont(font)
        self.vel_title.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.vel_title.setAlignment(QtCore.Qt.AlignCenter)
        self.vel_title.setObjectName("vel_title")
        self.verticalLayout_5.addWidget(self.vel_title)
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.label_vel_x = QtWidgets.QLabel(self.widget)
        self.label_vel_x.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.label_vel_x.setObjectName("label_vel_x")
        self.horizontalLayout_4.addWidget(self.label_vel_x)
        self.vel_x = QtWidgets.QLabel(self.widget)
        self.vel_x.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.vel_x.setObjectName("vel_x")
        self.horizontalLayout_4.addWidget(self.vel_x)
        self.verticalLayout.addLayout(self.horizontalLayout_4)
        self.horizontalLayout_5 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_5.setObjectName("horizontalLayout_5")
        self.label_vel_y = QtWidgets.QLabel(self.widget)
        self.label_vel_y.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.label_vel_y.setObjectName("label_vel_y")
        self.horizontalLayout_5.addWidget(self.label_vel_y)
        self.vel_y = QtWidgets.QLabel(self.widget)
        self.vel_y.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.vel_y.setObjectName("vel_y")
        self.horizontalLayout_5.addWidget(self.vel_y)
        self.verticalLayout.addLayout(self.horizontalLayout_5)
        self.horizontalLayout_6 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_6.setObjectName("horizontalLayout_6")
        self.label_vel_yaw = QtWidgets.QLabel(self.widget)
        self.label_vel_yaw.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.label_vel_yaw.setObjectName("label_vel_yaw")
        self.horizontalLayout_6.addWidget(self.label_vel_yaw)
        self.vel_yaw = QtWidgets.QLabel(self.widget)
        self.vel_yaw.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.vel_yaw.setObjectName("vel_yaw")
        self.horizontalLayout_6.addWidget(self.vel_yaw)
        self.verticalLayout.addLayout(self.horizontalLayout_6)
        self.verticalLayout_5.addLayout(self.verticalLayout)
        self.verticalLayout_7.addLayout(self.verticalLayout_5)
        self.verticalLayout_6 = QtWidgets.QVBoxLayout()
        self.verticalLayout_6.setObjectName("verticalLayout_6")
        self.title_wheel = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setPointSize(24)
        self.title_wheel.setFont(font)
        self.title_wheel.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.title_wheel.setAlignment(QtCore.Qt.AlignCenter)
        self.title_wheel.setObjectName("title_wheel")
        self.verticalLayout_6.addWidget(self.title_wheel)
        self.verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.horizontalLayout_7 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_7.setObjectName("horizontalLayout_7")
        self.label_vel_right = QtWidgets.QLabel(self.widget)
        self.label_vel_right.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.label_vel_right.setObjectName("label_vel_right")
        self.horizontalLayout_7.addWidget(self.label_vel_right)
        self.vel_wheel_right = QtWidgets.QLabel(self.widget)
        self.vel_wheel_right.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.vel_wheel_right.setObjectName("vel_wheel_right")
        self.horizontalLayout_7.addWidget(self.vel_wheel_right)
        self.verticalLayout_3.addLayout(self.horizontalLayout_7)
        self.horizontalLayout_8 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_8.setObjectName("horizontalLayout_8")
        self.label_vel_left = QtWidgets.QLabel(self.widget)
        self.label_vel_left.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.label_vel_left.setObjectName("label_vel_left")
        self.horizontalLayout_8.addWidget(self.label_vel_left)
        self.vel_wheel_left = QtWidgets.QLabel(self.widget)
        self.vel_wheel_left.setStyleSheet("QLabel{\n"
"    border: 2px solid black;\n"
"}\n"
"")
        self.vel_wheel_left.setObjectName("vel_wheel_left")
        self.horizontalLayout_8.addWidget(self.vel_wheel_left)
        self.verticalLayout_3.addLayout(self.horizontalLayout_8)
        self.verticalLayout_6.addLayout(self.verticalLayout_3)
        self.verticalLayout_7.addLayout(self.verticalLayout_6)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1103, 20))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.emergency.setText(_translate("MainWindow", "Emergency"))
        self.state_title.setText(_translate("MainWindow", "Robot_State"))
        self.state.setText(_translate("MainWindow", "No_State"))
        self.pose_title.setText(_translate("MainWindow", "Pose"))
        self.label_x.setText(_translate("MainWindow", "x"))
        self.pose_x.setText(_translate("MainWindow", "0.0"))
        self.label_y.setText(_translate("MainWindow", "y"))
        self.pose_y.setText(_translate("MainWindow", "0.0"))
        self.label_yaw.setText(_translate("MainWindow", "yaw"))
        self.pose_yaw.setText(_translate("MainWindow", "0.0"))
        self.vel_title.setText(_translate("MainWindow", "vel_cmd"))
        self.label_vel_x.setText(_translate("MainWindow", "vel_x"))
        self.vel_x.setText(_translate("MainWindow", "0.0"))
        self.label_vel_y.setText(_translate("MainWindow", "vel_y"))
        self.vel_y.setText(_translate("MainWindow", "0.0"))
        self.label_vel_yaw.setText(_translate("MainWindow", "vel_yaw"))
        self.vel_yaw.setText(_translate("MainWindow", "0.0"))
        self.title_wheel.setText(_translate("MainWindow", "vel_wheel"))
        self.label_vel_right.setText(_translate("MainWindow", "vel_wheel_right"))
        self.vel_wheel_right.setText(_translate("MainWindow", "0.0"))
        self.label_vel_left.setText(_translate("MainWindow", "vel_wheel_left"))
        self.vel_wheel_left.setText(_translate("MainWindow", "0.0"))
