#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string xorOperation(string a , string b){
    string result = "";
    for(int i = 0 ; i < b.length() ; i++){
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

string mod2Divisor(string dividend , string divisor){
    int pick = divisor.length();
    string temp = dividend.substr(0,pick);
    while(pick < dividend.length()){
        if(temp[0] == '1'){
            temp = xorOperation(temp,divisor);
        } else {
            string zeros(divisor.length() , '0');
            temp = xorOperation(temp,zeros);
        }
        temp = temp.substr(1) + dividend[pick];
        pick++;
    }
    if(temp[0] == '1'){
        temp = xorOperation(temp,divisor);
    } else {
        string zeros(divisor.length(),'0');
        temp = xorOperation(temp,zeros);
    }
    return temp.substr(1);
}

int main(){
    string data , generator;
    cout << "Enter the dividend (data) " << endl;
    getline(cin,data);
    cout << "Enter the divisor (generator) " << endl;
    getline(cin,generator);
    int data_len = data.length(); 
    int gen_len = generator.length();

    string appended_string = data + string(gen_len - 1 , '0');

    string remainder = mod2Divisor(appended_string , generator);

    string final_code = data + remainder;

    cout << "CRC value is : " << remainder << endl;
    cout << "Final codeword is : " << final_code << endl;

    string corrected = mod2Divisor(final_code , generator);
    int a = stoi(corrected);
    if(a == 0){
        cout << "No error in crc " << endl;
    } else {
        cout << "Error in crc " << endl;
    }
    return 0;
}