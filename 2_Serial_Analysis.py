import time
import serial
ser = serial.Serial('/dev/ttyACM0',9600,timeout = 1)


gassensor_value = "no default_value"
temperaturesensor_value = "no default_value"
stromsensor_value = "no default_value"


sensor_value = [['gassensor',gassensor_value],['temperaturesensor',temperaturesensor_value],['stromsensor',stromsensor_value]]

i = 0
try:
    while 1:
        time.sleep(10)
        if(i == 0):
            sensor_value[0][1] = ser.readline()
            i = i + 1
        elif(i == 1):
            sensor_value[1][1] = ser.readline()
            i = i + 1
        elif(i == 2):
            sensor_value[2][1] = ser.readline()
            i == 0

        if(sensor_value[0][1] != "no default_value" or sensor_value[0][1] != b''):
            print (sensor_value[0])

        if (sensor_value[1][1] != "no default_value" or sensor_value[1][1] != b''):
            print(sensor_value[1])

        if (sensor_value[2][1] != "no default_value" or sensor_value[2][1] != b''):
            print(sensor_value[2])


except KeyboardInterrupt:
    ser.close()

