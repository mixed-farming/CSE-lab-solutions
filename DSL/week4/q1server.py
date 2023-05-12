import socket as s
import time
sock = s.socket(s.AF_INET, s.SOCK_DGRAM)
host = '127.0.0.1'
port = 12345
sock.bind((host, port))
while True:
    print("Waiting for client")
    data,addr = sock.recvfrom(1024)
    print("Received messages: ", data.decode(),"from ", addr)
    currentTime = time.ctime(time.time()) + "\n"
    bytesToSend = str.encode(currentTime)
    sock.sendto(bytesToSend, addr)