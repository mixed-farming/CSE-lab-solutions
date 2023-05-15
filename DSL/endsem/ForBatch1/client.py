import socket
host='localhost'
port=10000
s=socket.socket()
s.connect((host,port))
n=input('Enter the words : ').split()
print(n)
s.send(str(n).encode())
print('Array sent')
data=s.recv(1024)
print('Vowels : ',data.decode())
data=s.recv(1024)
print('Consonants : ',data.decode())
s.close()