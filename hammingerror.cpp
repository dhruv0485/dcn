#include<iostream>
using namespace std;

int main(){
    int arr[7];
    cout << "Enter hamming code " << endl;
    for(int i = 0 ; i < 7 ; i++){
        cin >> arr[i];
    }
    int p1 = arr[2] ^ arr[4] ^ arr[6];
    int p2 = arr[2] ^ arr[4] ^ arr[5];
    int p4 = arr[4] ^ arr[5] ^ arr[6];
    if(p1 == arr[0] || p2 == arr[1] || arr[3] == p4){
        cout << "Valid hamming code" << endl;
    } else {
        cout << "Invalid hamming code" << endl;
    }
    return 0;
}