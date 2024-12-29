# -*- coding: utf-8 -*-
import numpy as np
import cv2 
import sys
 
aruco = cv2.aruco #arucoライブラリ
dictionary = aruco.getPredefinedDictionary(aruco.DICT_5X5_250)

def arReader(): 
    print(cv2.getBuildInformation())
    cap = cv2.VideoCapture(0)
    cnt=0

    while (cap.isOpened()):
        ret, frame = cap.read()
        
        if ret == True:
            # フレームを表示
            cv2.imshow('Webcam Live', frame)
 
            corners, ids, rejectedImgPoints = aruco.detectMarkers(frame, dictionary) #マーカを検出
            print(corners,ids)
            aruco.drawDetectedMarkers(frame, corners, ids, (0,255,0)) #検出したマーカに描画
            cv2.imshow('result',frame)
            cnt+=1
            # 'q'キーが押されたらループから抜ける
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
        
        else:
            print("errer")
            break
            

    cap.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    arReader()
