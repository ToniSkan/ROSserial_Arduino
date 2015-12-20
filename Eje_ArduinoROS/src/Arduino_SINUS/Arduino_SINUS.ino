//rosserial PUBLISHER of SINUS value and LED Blinking

#include <math.h>
#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>


ros::NodeHandle nh;					//Instantiate Node Handle
std_msgs::Float32 sinusROS_msg;				//declare std_msgs Float32 type
std_msgs::String str_msg;
ros::Publisher pub_sinus("sinus", &sinusROS_msg);	//Instiantiate the PUBLISHERS topic: sinus, sinusROS_msg is the message
ros::Publisher chatter("chatter", &str_msg);          //topic: chatter, str_msg is the message (string) to send

const float Pi= 3.141593;
float alpha = 0;
int led=13;			      //Digital PIN=13. of Arduino Mainboard
char hello[13] = "hello world!";      //Load string value

void setup()
{
//SETUP
	nh.initNode();				//Initialize ROS node handle, 
  	nh.advertise(pub_sinus);		//advertise any topics being published, and subscribe to any topics we wish to listen to. 
	nh.advertise(chatter);                  //advertise chatter topic
        pinMode(led, OUTPUT);			//Configure Arduino Board PIN13 as Output
}


void loop()
{
 //COMPUTE SINUS and set LED ON if value of sinus < PI
   	 alpha = alpha + 0.1;
      	if (alpha>2*Pi) alpha=0;
      
     	//Blink led
     	 if (alpha>Pi)
        	digitalWrite(led, LOW);
      	else
       		digitalWrite(led, HIGH);

//PUBLISH MESSAGE
  	sinusROS_msg.data = sin(alpha);		//Message = Sinus(alpha)
 	pub_sinus.publish(&sinusROS_msg);	//publish message. //Here the Node publish the sinus value
     	str_msg.data = hello;                   //Message= hello
        chatter.publish(&str_msg);              //publish chatter message
        nh.spinOnce();				//with spinOnce all ROS communication callbacks are handled.
  						//spin (ros sync and attend callbacks, if any....)
// Sleep
  	delay(400);                  



//http://wiki.ros.org/rosserial_arduino/Tutorials

}







