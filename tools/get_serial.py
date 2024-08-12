import serial
from sys import platform
from time import localtime

baudrate = 9600 
port = ''

if platform == 'linux':
	# TODO: nem sempre ele vai pra essa porta, esse caso ocorre
	#			ocorre apenas quando não há nenhum outro dispositivo
	#			conectado.
	port = '/dev/ttyUSB0'

else:
	# TODO: aqui é o mesmo caso no de cima, mas no windows.
	port = 'COM3'


ser = serial.Serial(port, baudrate)

# TODO: ctrl+c pra sair do script de maneira decente
while(True):
	log = ser.readline()
	log = log.decode("utf-8")

	time = localtime()

	hour = time.tm_hour
	minutes = time.tm_min
	sec = time.tm_sec

	print(f"[{hour}:{minutes}:{sec}] {log}")
