# Python3 program imitating a clock server
import socket
import datetime
# function used to initiate the Clock Server
def initiateClockServer():
    print('Manipal buddy banking\n')
    s = socket.socket()
    print("Socket successfully created")
    # Server port
    port = 8011
    s.bind(('', port))
    # Start listening to requests
    s.listen(2)
    print("Socket is listening...")

    num_clients=0
    # Clock Server Running forever
    while num_clients<2:
    # Establish connection with client
        connection, address = s.accept()
        print('Server connected to', address)
        # Respond the client with server clock time
        connection.send(str(datetime.datetime.now()).encode())
        # Close the connection with the client process
        connection.close()
        num_clients+=1
        
# Driver function
if __name__ == '__main__':
    # Trigger the Clock Server
    initiateClockServer()
