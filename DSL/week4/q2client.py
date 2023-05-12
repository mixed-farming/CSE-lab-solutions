import socket as s
host='127.0.0.1'
port=10002
sock=s.socket(s.AF_INET, s.SOCK_DGRAM)
msg=input("Type some text to send : ")
print("1. Client Sent: ", msg)
sock.sendto (msg.encode(), (host, port))
while True:
    msg,addr=sock.recvfrom (1024)
    print("2. Client received: ",msg.decode())
    msg=input("1. Client Sent: ")
    sock.sendto(msg.encode(), addr)