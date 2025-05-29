import socket
import os

def handle_client(conn):
    while True:
        command = conn.recv(1024).decode()

        if command == "HELLO" :
            conn.send("HELLO CLIENT".encode())
        elif command == "FILE" :
            filename = conn.recv(1024).decode()
            if os.path.exists(filename):
                conn.send("FOUND FILE".encode())
                with open(filename,'rb') as f:
                    data = f.read()
                    conn.send(data)
                print("File sent successfully")
            else :
                conn.send("NOT FOUND".encode())
        elif command == "CALC" :
            expression = conn.recv(1024).decode()
            try:
                result = str(eval(expression))
            except Exception as e:
                result = f"Error: {e}"
            conn.send(result.encode())
        elif command == "EXIT":
            print("Connection closed by client")
            break
        else:
            conn.send("INVALID COMMAND".encode())
    conn.close()

def start_server():
    host = '0.0.0.0'
    port = 5001
    s = socket.socket(socket.AF_INET , socket.SOCK_STREAM)
    s.bind((host,port))
    s.listen(1)
    print(f"Server listening on {host} : {port}")
    conn , addr = s.accept()
    print(f"Connected to {addr}")
    handle_client(conn)

start_server()