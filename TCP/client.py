import socket 

def start_client():
    host = '127.0.0.1'
    port = 5001
    s = socket.socket(socket.AF_INET , socket.SOCK_STREAM)
    s.connect((host,port))

    while True:
        print("\n Choose an option")
        print("\n 1. Say Hello")
        print("\n 2. File transfer")
        print("\n 3.Calculator")
        print("\n 4.Exit \n")
        choice = input("Enter your choice : ")
        if choice == '1':
            s.send("HELLO".encode())
            print("Server says: ",s.recv(1024).decode())
        elif choice == '2':
            s.send("FILE".encode())
            filename = input("\n Enter filename")
            s.send(filename.encode())
            status = s.recv(1024).decode()
            if status == "FOUND":
                data = s.recv(4096)
                with open("recieved_" + filename , 'wb') as f:
                    f.write(data)
                print("File recieved")
            else:
                print("File not found")
        elif choice == '3':
            s.send("CALC".encode())
            expr = input("\n Enter your expression : ")
            s.send(expr.encode())
            result = s.recv(1024).decode()
            print("Result : ",result)
        elif choice == '4':
            s.send("EXIT".encode())
            break
        else:
            print("INVALID OPTION")
    s.close()

start_client()