# -*- coding: utf-8 -*-
import paho.mqtt.client as mqtt
import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600)

gassensor_value = "no default_value"
temperaturesensor_value = "no default_value"
stromsensor_value = "no default_value"


sensor_value = [['/Deutschland/Osnabrueck/Coffee-bike-1/Sensor_1',gassensor_value],['/Deutschland/Osnabrueck/Coffee-bike-1/Sensor_2',temperaturesensor_value],['/Deutschland/Osnabrueck/Coffee-bike-1/Sensor_3',stromsensor_value]]




def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    # print(client.subscribe("/Deutschland/Osnabrueck/Coffee-bike-1/Sensor_1"))


def on_publish(client, obj, mid):
    print("mid: " + str(mid))


client = mqtt.Client()
client.on_connect = on_connect
client.on_publish = on_publish
client.connect("192.168.1.2", 1883, 60)
# 为什么这里不能用forvever
client.loop_start()
try:
    i = 0
    while (True):
        time.sleep(10)
        if (i == 0):
            sensor_value[0][1] = ser.readline()
            i = i + 1
        elif (i == 1):
            sensor_value[1][1] = ser.readline()
            i = i + 1
        elif (i == 2):
            sensor_value[2][1] = ser.readline()
            i == 0

        if (sensor_value[0][1] != "no default_value" or sensor_value[0][1] != b''):
            print(sensor_value[0])
            client.publish("/Deutschland/Osnabrueck/Coffee-bike-1/Sensor_1", sensor_value[0][1])

        if (sensor_value[1][1] != "no default_value" or sensor_value[1][1] != b''):
            print(sensor_value[1])
            client.publish("/Deutschland/Osnabrueck/Coffee-bike-1/Sensor_2", sensor_value[1][1])

        if (sensor_value[2][1] != "no default_value" or sensor_value[2][1] != b''):
            print(sensor_value[2])
            client.publish("/Deutschland/Osnabrueck/Coffee-bike-1/Sensor_3", sensor_value[2][1])


except KeyboardInterrupt:
    ser.close()

