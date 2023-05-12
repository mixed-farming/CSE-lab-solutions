import socket as s
host='169.254.44.122'
port=10002
sock=s.socket()
sock.connect((host,port))
while True:
    msg=input("Type some text to send : ")
    print("1. Client Sent: ", msg)
    sock.send(str.encode(msg))
    if msg.find('exit')!=-1:
        break
    msg=sock.recv(1024)
    msg=msg.decode()
    print("2. Client received: ",msg)
    if msg.find('exit')!=-1:
        break