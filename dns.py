import socket 

while True:
    print("\n menu \n 1.gethostbyname \n 2.gethostbyaddress")
    choose = input("\n Enter your choice : ")
    if choose == '1':
        a = input("\n enter url : ")
        addr1 = socket.gethostbyname(a)
        print("ip address is : ",addr1)

    elif choose == '2':
        b = input("\n enter ip address")
        addr2 = socket.gethostbyaddr(b)
        print("url is : " , addr2)

    elif choose == '3':
        exit()

    else:
        print("\n Invalid choice \n")