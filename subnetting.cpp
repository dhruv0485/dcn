#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
using namespace std;

int main(){
    string Ip;
    int a1 , a2 , a3 , a4;
    cout << "Enter Ip address" << endl;
    getline(cin,Ip);

    int cidr;
    cout << "Enter CIDR value " << endl;
    cin >> cidr;

    cout << endl;

    stringstream ss(Ip);
    char dot = '.';

    ss >> a1 >> dot >> a2 >> dot >> a3 >> dot >> a4;
    if(a1 > 0 && a1 <= 127){
        cout << "IP address belongs to class A " << endl;
        cout << "Default subnet mask 255.0.0.0" << endl;
    } else if (a1 >= 128 && a1 <= 191){
        cout << "IP address belongs to class B" << endl;
        cout << "Default subnet mask 255.255.0.0" << endl;
    } else if (a1 >= 192 && a1 <= 223){
        cout << "IP address belongs to class C" << endl;
        cout << "Default subnet mask 255.255.255.0" << endl;
    } else if (a1 >= 224 && a1 <= 239){
        cout << "IP address belongs to class D" << endl;
        cout << "No default subnet" << endl;
    } else if (a1 >= 240 && a1 <= 255){
        cout << "IP address belongs to class E" << endl;
        cout << "No default subnet mask" << endl;
    }

    int bits;

    if(a1 > 0 && a1 <= 127){
        bits = cidr - 8;
    } else if (a1 >= 128 && a1 <= 191){
        bits = cidr - 16;
    } else if (a1 >= 192 && a1 <= 223){
        bits = cidr - 24;
    }

    int net = pow(2,bits);
    cout << "No of networks " << net << endl;
    int borrowbits = 8 - bits;
    int ipbits = pow(2,borrowbits);
    cout << "No of ip address " << ipbits << endl;
    int hostbits = pow(2,borrowbits) - 2;
    cout << "No of host bits " << hostbits << endl;

    int cidrld = 0;
    for(int i = bits; i < 8 ; i++){
        cidrld += pow(2,i);
    }

    int firstadd = cidrld & a4;

    cout << "First Ip address is : " << a1 << "." << a2 << "." << a3 << "." << firstadd << endl;

    int rev = 255 - cidrld;
    int lastaddr = rev | a4;
    cout << "Last address is : " << a1 << "." << a2 << "." << a3 << "." << lastaddr << endl;

    int network_col = 256 / net;
    // 16 

    int k = 1; int count = 0;
    for(int i = 0 ; i < 256 ; i++){
        if(count == 0){
            cout << "Network Column " << k << endl;
            count = 1;
        }
        cout << a1 << "." << a2 << "." << a3 << "." << i << endl;
        if((i+1) % network_col == 0){
            count = 0;
            k++;
        }
    }
    return 0;
}