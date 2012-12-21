import serial, requests
#replace this with your serial device.
# ser = serial.Serial('/dev/tty.usbmodemfd141', 9600)

ser = serial.Serial('/dev/tty.usbmodemfd131', 9600)
#ser = serial.Serial('/dev/tty.usbserial-A800I2RW', 9600)
siteStartChar = 0x04
siteEndChar = 0x05
postStartChar = 0x06
postEndChar = 0x07
dataStartChar = 0x08
dataEndChar = 0x03
postData = ""
postRequest = ""
site = ""
def readValue(endChar):
	tmp = ""
	while 1:
		val = ser.read()
		if ord(val) == endChar:
			return tmp
		tmp += val
		#print tmp
def put(s, r, d):
	#"http://192.168.1.10/api/22a828f1898a4257c3f181e753241337/lights/1/state"
	r = requests.put(s+r, data=d)
	resp = r.content
	print resp;
	ser.write(resp)

while 1:
	# put("http://192.168.1.10/api/","22a828f1898a4257c3f181e753241337/lights/1/state",'{"on":true}');
	val = ser.read()
	if ord(val) == siteStartChar:
		site = ""
		postRequest = ""
		postData = ""
		site = readValue(siteEndChar)
		print 'postSite=', site
	elif ord(val) == postStartChar:
		postRequest = ""
		postRequest = readValue(postEndChar)
		print 'postRequest=', postRequest
	elif ord(val) == dataStartChar:
		postData = ""
		postData = readValue(dataEndChar)
		print 'postData=', postData
		put(site, postRequest, postData)
	else:
		print val
