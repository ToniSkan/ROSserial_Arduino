# ROSserial_Arduino
rosserial Package with Publisher and Suscriber example 

##Arduino_SINUS Program:
PUBLISH TO MESSGES:
	Float32: sinusROS_msg: Sinus value ---->  TOPIC: SINUS
	String: str_msg: "Hello World!" String -> TOPIC: chatter

##BLINKING Program:
SUSCRIBER:
	toggle_led TOPIC to power ON/OFF OnBoard Led of output13 Arduino Board



##----------------------------------WITH ROSLAUNCH-----------------------------------------##
BUILD CATKIN PACKAGE
$ catkin_make --pkg Eje_ArudinoROS

UPLOAD CODE TU ARDUINO BOARD

Terminal 1:
$ roslaunch Eje_ArduinoROS rosserial.launch

Terminal 2:
$ rostopic list

If Arudino_SINUS is the program uploaded to arduino:
$ rostopic echo sinus
$ rostopic echo chatter	

If Bliking is the program uploaded to arduino:
$ rostopic pub toggle_led std_msgs/Empty --once





##----------------------------------WITHOUTH ROSLAUNCH-----------------------------------------##
##Arduino_SINUS
UPLOAD CODE TU ARDUINO BOARD

Terminal 1:
$ roscore

Terminal 2:
$ rosrun rosserial_python serial_node.py /dev/ttyACM2

	ACMx --> x Depending on the port assigned by VMware Virtual machine

Terminal 3:
$ rostopic echo sinus
or
$ rostopic echo chatter

##BLINKING
UPLOAD CODE TU ARDUINO BOARD

Terminal 1:
$ roscore

Terminal 2:
$ rosrun rosserial_python serial_node.py /dev/ttyACM2

	ACMx --> x Depending on the port assigned by VMware Virtual machine

Terminal 3:
$ rostopic pub toggle_led std_msgs/Empty --once

##Toni Guasch
