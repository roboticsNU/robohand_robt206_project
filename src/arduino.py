import serial
import numpy as np

ser = serial.Serial('/dev/tty.usbmodem1421', 9600)
i = 0
while True:
	i += 1
	data = ser.readline()
	f = open("arduino_data.txt", "w")
	print(data)
	f.write(data)
	f.close()
