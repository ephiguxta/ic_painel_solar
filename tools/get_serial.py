import serial
from sys import platform
from time import localtime

baudrate = 115200
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

	# TODO: quando tiver apenas um dígio, por exemplo '15:26: 0',
	#			cole o o zero no segundo dois pontos, ex: '15:26:0'
	#
	print(f"[{hour:2}:{minutes:2}:{sec:2}] {log}", end='')
