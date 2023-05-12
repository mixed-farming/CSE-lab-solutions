import socket as s
sock = s.socket(s.AF_INET, s.SOCK_DGRAM)
host = '127.0.0.1'
port = 12345
msg = "Hello UDP Server!"
sock.sendto(msg.encode(), (host, port))
msgFromServer,addr = sock.recvfrom(1024)
msg = "Message from Server " + msgFromServer.decode()
print(msg)