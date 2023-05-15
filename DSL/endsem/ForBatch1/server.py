import socket
host='localhost'
port=10000
s=socket.socket()
s.bind((host,port))
s.listen(5)
print('TCP server is open and ready for connection...')
conn,addr=s.accept()
data=conn.recv(1024)
l=data.decode().strip('[]').split(', ')
print('Received : ',l)
v,c=[],[]
for i in l:
    for j in i:
        if j=='a' or j=='e' or j=='i' or j=='o' or j=='u' or j=='A' or j=='E' or j=='I' or j=='O' or j=='U':
            v.append(j)
        elif j!='\'' and j!=' ':
            c.append(j)
print('Vowels : ',v)
print('Consonents : ',c)
conn.send(str(len(v)).encode())
conn.send(str(len(c)).encode())
conn.close()
s.close()