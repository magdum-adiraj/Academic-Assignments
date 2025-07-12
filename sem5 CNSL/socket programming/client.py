import socket,math

host="100.80.5.251"
port=9999
s=socket.socket()

s.connect((host,port))
print("Client ready to solve...")
while True:
    data=str(s.recv(1024),'utf-8')
    if data=='q':
        s.close()
        break
    print("Solving: ",data)
    try:
        output=eval(data)
    except:
        output="Not a proper calculation"
s.send(str.encode(str(output),'utf-8'))
print("Sent result...")