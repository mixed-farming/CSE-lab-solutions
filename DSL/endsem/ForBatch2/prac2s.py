import socket
host='localhost'
port=10000
s=socket.socket()
s.bind((host,port))
s.listen(5)
print('TCP server is open and ready for connection...')
conn,addr=s.accept()
data=conn.recv(1024)
l=[float(x) for x in data.decode().strip('[]').split(',')]
esum,osum=0,0
print('Sum of digits in list : ')
for n in l:
    summ=0
    n=int(n)
    while n>0:
        summ+=(n%10)
        n//=10
    print(summ)
    if summ%2==0:
        esum+=summ
    else:
        osum+=summ
conn.send(str(esum).encode())
conn.send(str(osum).encode())
conn.close()
s.close()
