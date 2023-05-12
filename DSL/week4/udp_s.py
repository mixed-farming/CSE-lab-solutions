import socket as s
sock=s.socket(s.AF_INET,s.SOCK_DGRAM)#create a socket
host='127.0.0.1'
port=10002
sock.bind((host,port))#bind it to the address
while True:
    print("Waiting for client...")
    data,addr=sock.recvfrom(1024)#recvfrom returns data and address of client
    data=data.decode()#decode the received output
    if data==data[::-1]:
        print(f"{data} is a palindrome.")
        msg=f"{data} is a palindrome."
        sock.sendto(str.encode(msg),addr)#send output as an encoded string to the address obtained previously
    else:
        print(f"{data} is not a palindrome.")
        msg=f"{data} is not a palindrome."
        sock.sendto(str.encode(msg),addr)