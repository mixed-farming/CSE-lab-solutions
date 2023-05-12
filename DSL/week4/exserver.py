import socket as s
sock = s.socket(s.AF_INET,s.SOCK_DGRAM)
host = '127.0.0.1'
port = 12345
sock.bind((host, port))
while True:
    print("Waiting for client...")
    data,addr = sock.recvfrom(1024) #receive data from client
    print("Received Messages:",data.decode()," from",addr)