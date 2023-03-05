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
    data = int(data)
    text=0
    while data>0:
        text=text*10+(data%10)
        data=data//10
    msg=f"Reverse number : {text}"
    print(msg)
    conn.send(str.encode(msg))#send it to connection client as a encoded string
    
