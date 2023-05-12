import socket
host='localhost'
port=10000
s=socket.socket()
s.connect((host,port))
n=[int(x) for x in input('Enter the numbers : ').split()]
data=[float(x) for x in n]
print(data)
s.send(str(data).encode())
print('Array sent')
data=s.recv(1024)
print('Sum of even sums : ',data.decode())
data=s.recv(1024)
print('Sum of odd sums : ',data.decode())
s.close()