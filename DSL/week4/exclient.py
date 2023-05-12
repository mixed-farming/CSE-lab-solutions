import socket as s
sock = s.socket(s.AF_INET,s.SOCK_DGRAM)
host = '127.0.0.1'
port = 12345
msg = "UDP Program!"
print("UDP target IP:", host)
print("UDP target Port:", port)
sock.sendto(msg.encode(),(host,port))