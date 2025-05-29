import os
import socket 

SERVER_IP = '127.0.0.1'
PORT = 5005
BUFFER_SIZE = 65507

sock = socket.socket(socket.AF_INET , socket.SOCK_DGRAM)

file_input = input("\n Enter file names to be send (comma seperated)")
files_to_send = [file.strip() for file in file_input.split(',')]

for file_path in files_to_send:
    if not os.path.exists(file_path):
        print(f"File not found : {file_path}")
        continue

    filename = os.path.basename(file_path)
    print(f"Sending file : {filename}")
    
    sock.sendto(filename.encode() , (SERVER_IP,PORT))

    with open(file_path,"rb") as f:
        while True:
            chunk = f.read(BUFFER_SIZE)
            if not chunk:
                break
            sock.sendto(chunk,((SERVER_IP,PORT)))

    sock.sendto(b"__END__",(SERVER_IP,PORT))
    print(f"{filename} send successfully. \n")


sock.close()