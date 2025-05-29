import socket 
import os 

SERVER_IP = '0.0.0.0'
PORT = 5005
BUFFER_SIZE = 65507

sock = socket.socket(socket.AF_INET , socket.SOCK_DGRAM)

sock.bind((SERVER_IP,PORT))
print(f"Server listening on {SERVER_IP} : {PORT}")


def recieve_file():
    data , addr = sock.recvfrom(BUFFER_SIZE)
    filename = data.decode()

    print(f"Recieving file : {filename} from {addr}")

    with open(f"recieved_{filename}","wb") as f:
        while True:
            data,_ = sock.recvfrom(BUFFER_SIZE)
            if data == b"__END__":
                print(f"{filename} recieved successfully")
                break
            f.write(data)

for _ in range(4):
    recieve_file()

sock.close()
