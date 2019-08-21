import serial


arduino = serial.Serial("COM8",9600)

def serialWrite(x):
   arduino .write(bytes(x.encode()))


serialWrite('%MM(500,00,0)?')
serialWrite('%MC(1)?)
ser.write(bytes(str.encode()))
