import serial
import sys

p = serial.Serial('/dev/ttyACM0', 9600);
p.write('s');
f = open('dados.txt', 'w')
f.close()

while(not 0):	
	f = open('dados.txt', 'a')
	data = p.read();
	sys.stdout.write(data);
	f.write(data);
	f.close()
