import socket as s
host='127.0.0.1'
port=10000
sock=s.socket(s.AF_INET,s.SOCK_STREAM)#create socket
sock.bind((host,port))#bind its address
sock.listen(5)#start listening to clients
conn,addr=sock.accept()#accept the requests of clients
print('Waiting for client...')
while True:
    data = conn.recv(1024)#new connection(conn) recv returns only data
    data = data.decode()
    if not data.isdigit():
        continue
    data = int(data)
    flag=1
    for i in range(2,data,1):
        if data%i==0:
            flag=0
    if flag==1 and data!=1:
        msg=f"{data} is a prime number."
        print(f"{data} is a prime number.")
        conn.send(str.encode(msg))#send it to connection client as a encoded string
    else:
        msg=f"{data} is not a prime number."
        print(f"{data} is not a prime number.")
        conn.send(str.encode(msg))
