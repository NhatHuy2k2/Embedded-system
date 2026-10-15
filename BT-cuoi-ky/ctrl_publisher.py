#!/usr/bin/env python3

import rospy
from std_msgs.msg import Float64, String

import RPi.GPIO as GPIO
import time

straight = 20
GPIO.setmode(GPIO.BCM)
GPIO.setup(straight, GPIO.IN, GPIO.PUD_DOWN)

left = 21
GPIO.setup(left, GPIO.IN, GPIO.PUD_DOWN)

right = 19
GPIO.setup(right, GPIO.IN, GPIO.PUD_DOWN)

back = 26
GPIO.setup(back, GPIO.IN, GPIO.PUD_DOWN)

global message1, message2

def Publisher():
    rospy.init_node("continuous_publisher")
    joint1 = rospy.Publisher('my_diffbot/joint1_velocity_controller/command', Float64, queue_size=10)
    joint2 = rospy.Publisher('/my_diffbot/joint2_velocity_controller/command', Float64, queue_size=10)
    rospy.Publisher('string_publish', String, queue_size=10)
    rate = rospy.Rate(10)

    velRight = 0
    velLeft = 0

    message1 = Float64()
    message2 = Float64()

    while not rospy.is_shutdown():
        if GPIO.input(straight) == 1:
            velRight = 5
            velLeft = -5
            rospy.loginfo("straight")

        elif GPIO.input(back) == 1:
            velRight = -5
            velLeft = 5
            rospy.loginfo("back")

        elif GPIO.input(left) == 1:
            velRight = 1
            velLeft = -9
            rospy.loginfo("left")

        elif GPIO.input(right) == 1:
            velRight = 9
            velLeft = -1
            rospy.loginfo("right")
        elif (GPIO.input(straight) == 0)&(GPIO.input(back) == 0)&(GPIO.input(left) == 0)&(GPIO.input(right) == 0):
            velRight = 0
            velLeft =  0
            rospy.loginfo("stop")

        message1.data = float(velRight)
        message2.data = float(velLeft)

        joint1.publish(message1)
        joint2.publish(message2)

        rate.sleep()

if __name__ == "__main__":
    Publisher()
