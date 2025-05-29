#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool isSent(){
    return ((rand() % 100) < 70); 
}

int main(){
    srand(time(0));
    int total = 10;
    int windowSize = 3;
    int sender[total] = {1,2,3,4,5,6,7,8,9,10};
    int reciever[total] = {0};

    int lastSent = -1;

    cout << "Sending frames" << endl;
    for(int i : sender)
    cout << i << " ";
    cout << endl;

    while(lastSent < total-1){
        for(int i = 0 ; i < 3 && i + lastSent + 1 < total ; i++){
            cout << "Sending frames : " << sender[i + lastSent + 1] << endl;
        }
        cout << endl;

        bool error = 0;
        int last = lastSent;
        for(int i = 0 ; i < 3 ; i++){
            int curr = i + last + 1;
            if(curr >= total)
            break;
            cout << "Recieving frames " << sender[curr];
            
            if(isSent()){
                cout << "Success" << endl;
                if(!error){
                    lastSent = curr;
                    reciever[curr] = sender[curr];
                }
            } else {
                error = 1;
                cout << "Failure" << endl;
            }
        }
        cout << endl;
    }
    cout << "Recieved frames " << endl;
    for(int i : reciever){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}