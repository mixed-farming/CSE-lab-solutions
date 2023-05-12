import socket as s
port=10002
host='127.0.0.1'
sock=s.socket(s.AF_INET, s.SOCK_DGRAM)
sock.bind((host, port))
while True:
    print("####### Server is listening #######")
    msg,addr=sock.recvfrom (1024)
    print("1. Server received: ", msg.decode())
    msg=input("Type some text to send : ")
    print("2. Server sent : ", msg)
    sock.sendto(msg.encode(), addr)