import socket as s
sock=s.socket(s.AF_INET,s.SOCK_DGRAM)#create socket
host='127.0.0.1'
port=10002
while True:
    n=input("Enter a number : ")
    sock.sendto(str.encode(n),(host,port))#send input as an encoded string to specified host-port address
    print("Client sent : ",n)
    data,addr = sock.recvfrom(1024)#recvfrom returns data and address of server
    print(data.decode())#decode the data obtained before printing
