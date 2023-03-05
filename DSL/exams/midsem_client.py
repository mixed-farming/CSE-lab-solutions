import socket as s
host='127.0.0.1'
port=10000
sock=s.socket(s.AF_INET,s.SOCK_STREAM)#create socket
conn=sock.connect((host,port))#send connection request at specified host-port address
while True:
    n=input("Enter a number : ")
    sock.send(str.encode(n))#send input as an encoded string from client socket created
    print('Client sent : ',n)
    data=sock.recv(1024)
    print(data.decode())#decode the string to be printed