#include <ros.h>
#include <std_msgs/Empty.h>

ros::NodeHandle  nh;                                    //Instantiate Node Handle

void messageCb( const std_msgs::Empty& toggle_msg){     //Callback function="messageCb", type=std_msgs, message name=toggle_msg
  digitalWrite(13, HIGH-digitalRead(13));               //digitalwrite sets STATE of PIN13 to VALUE=1-ActualState (digitalread(13))
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );  //Instantiate Suscriber. Suscriber topic=toogle_led, type=std_msgs

void setup()
{ 
  pinMode(13, OUTPUT);
  nh.initNode();               //Initialize ROS node handle, 
  nh.subscribe(sub);          //advertise any topics being published
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}

