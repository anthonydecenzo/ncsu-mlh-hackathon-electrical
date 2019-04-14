#!/usr/bin/python

import requests
import serial
import time

water = ""


def sendPost(water):
	postURL = "http://142.93.202.103/api/v1/tasks/1"
	userId = "1"
	
	data = {'water':water}
	
	r = requests.put(url = postURL, data = data)
	print "Updated task to " + water



	

URL = "http://142.93.202.103/api/v1/tasks/1"
ser = serial.Serial('/dev/ttyACM0', 9600)
r = requests.get(url = URL)
data = str(r.json())
print data[13:14]
water = data[13:14]
	
while(1 == 1):
	if(ser.read() == 'L'):
		r = requests.get(url = URL)
		data = str(r.json())
		print ser.read()
		water = data[13:14]
	
		print data
		
		sendPost("t")		

		# for the practical use case
		# we'd read from the serial connection
		# to see whether to set the value to true or false
		#if(water == 'f'):
			
		#else:
		#	sendPost("f")
	
	
		active = 0
	elif(ser.read() == 'H'):
		sendPost("f")

	# time.sleep(5)



