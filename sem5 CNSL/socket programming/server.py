import socket
import sys

host=None
port=None
s=None

def create_socket():
    global host
    global port
    global s
    host=""
    port=9999
    try:
        s=socket.socket()
    except socket.error as e:
        pass

def bind_socket():
    global host
    global port
    global s
    try:
        s.bind((host,port))
        print("Listening...",end="")
        s.listen(5) 
    except socket.error as e:
        bind_socket()

def socket_accept():
    global host
    global port
    global s
    try:
        connection,address=s.accept()
        print(f"connection address: {address}")
        send_commands(connection)
        if connection:
            connection.close()
    except socket.error as e:
        pass

def send_commands(connection):
    while True:
        cmd= input("What to solve?\t=>") 
        if cmd=="q":
            connection.send(str.encode(cmd))
            connection.close()
            s.close()
            sys.exit()
        if len(str.encode(cmd)):
            connection.send(str.encode(cmd))
            response=str(connection.recv(1024),"utf-8")
            print("Solution: ",response)

def main():
    create_socket()
    bind_socket()
    socket_accept()

main()