#include<iostream>
using namespace std;

int main(){
    int arr[7];
    int d3 , d5 , d6 , d7;
    cout << "Enter the data bits " << endl;
    cin >> d3 >> d5 >> d6 >> d7;
    arr[2] = d3;
    arr[4] = d5;
    arr[5] = d6;
    arr[6] = d7;
    arr[0] = arr[2] ^ arr[4] ^ arr[6];
    arr[1] = arr[2] ^ arr[4] ^ arr[5];
    arr[3] = arr[4] ^ arr[5] ^ arr[6];
    cout << "The hamming code is : " << endl;
    for(int i = 0 ; i < 7 ; i++){
        cout << arr[i] << " | ";
    }
    cout << endl;
}