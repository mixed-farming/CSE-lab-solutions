import socket as s
port=10002
host='169.254.44.122'
sock=s.socket()
sock.bind((host, port))
sock.listen(5)
connection,addr=sock.accept()
print(connection,addr)
while True:
    print("####### Server is listening #######")
    msg=connection.recv(1024)
    msg=msg.decode()
    print("1. Server received: ", msg)
    if msg.find('exit')!=-1:
        break
    msg=input("Type some text to send : ")
    connection.send(str.encode(msg))
    print("2. Server sent : ", msg)
    if msg.find('exit')!=-1:
        break