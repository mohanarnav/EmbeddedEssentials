import serial

# Execute "sudo rfcomm bind /dev/rfcomm0 00:14:03:06:12:20" from terminal.

bluetoothSerial = serial.Serial("/dev/rfcomm0",baudrate=9600)
print("Bluetooth connected")
data=[];
len = 0;
file = open('logData.txt','w')

while 1:
    
    if(bluetoothSerial.readable()):
        data.append(bluetoothSerial.readline());
        print data[len]
        
        if(len<3000):
            file.write(data[len])
            len=len+1;
        else:
            file.close();
            break;
            
            
        
