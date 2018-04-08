# -*- coding: utf-8 -*-  
import paho.mqtt.client as mqtt
import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600 )



def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    #print(client.subscribe("/Deutschland/Osnabrueck/Coffee-bike-1/Sensor_1"))

def on_publish(client, obj, mid):

    print("mid: "+str(mid))


client = mqtt.Client()
client.on_connect = on_connect
client.on_publish = on_publish
client.connect("10.0.2.190", 1883, 60)
# 为什么这里不能用forvever

while(True):
    time.sleep(1)
    client.publish("/Deutschland/Osnabrueck/Coffee-bike-1/Sensor_2", ser.readline())

