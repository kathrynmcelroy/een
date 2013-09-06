import serial, sys, feedparser, time
#Settings - Change these to match your account details
USERNAME="YOUR EMAIL ADDRESS example bob@gmail.com"
PASSWORD="YOUR PASSWORD"
PROTO="https://"
SERVER="mail.google.com"
PATH="/gmail/feed/atom"
# PATH="/gmail/feed/atom/Bills" # for specific GMAIL label

SERIALPORT = "/dev/tty.usbmodemfd141" # Change this to your Arduino serial port!

# Set up serial port
try:
	ser = serial.Serial(SERIALPORT, 9600)
except serial.SerialException:
	print "no device connected - exiting"
	sys.exit()

var = 1
while var == 1 :  # This constructs an infinite loop
	newmails = int(feedparser.parse(PROTO + USERNAME + ":" + PASSWORD + "@" + SERVER + PATH)["feed"]["fullcount"])
	# Output data to serial port
	if newmails == 1: 
		ser.write("a")
		#ser.write("FLAG")
		#print "some mail"
		print newmails
		
	if newmails == 2: 
		ser.write("b")
		#ser.write("FLAG")
		#print "some mail"
		print newmails
		
	if newmails == 3: 
		ser.write("c")
		#ser.write("FLAG")
		#print "some mail"
		print newmails
		
	if newmails == 4: 
		ser.write("d")
		#ser.write("FLAG")
		#print "some mail"
		print newmails
		
	if newmails == 5: 
		ser.write("e")
		#ser.write("FLAG")
		#print "some mail"
		print newmails
		
	if newmails == 6: 
		ser.write("f")
		#ser.write("FLAG")
		#print "some mail"
		print newmails

	if newmails > 6: 
		ser.write("m")
		#print "no mail"
		print newmails
		
	if newmails == 0: 
		ser.write("n")
		#print "no mail"
		print newmails
		
	#print data to terminal

	time.sleep(10) # put a delay on the loop

# Close serial port
ser.close()

# RUN THIS SCRIPT TO SEND DATA TO ARDUINO
