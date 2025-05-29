#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool isSent(){
    return ((rand() % 100) < 50);
}

int main(){
    srand(time(0));
    int total = 10;
    int windowSize = 3; 
    int sender[total] = {1,2,3,4,5,6,7,8,9,10};
    int recieved[total] = {0};
    bool ack[total] = {0};

    cout << endl;
    cout << "Sending frames " << endl;
    for(int i : sender){
        cout << i << " ";
    }
    cout << endl;

    while(1){
        int limit = windowSize;
        for(int i = 0 ; i < total ; i++){
            if(ack[i] == 0){
                cout << "Sending frame  " << sender[i] << endl;
                limit--;
            }
            if(limit == 0)
            break;
        }
        if(limit == windowSize)
        break;
        limit = windowSize;
        for(int i = 0 ; i < total ; i++){
            if(ack[i] == 0){
                cout << "Recieving frames : " << sender[i];
                limit--;
                if(isSent()){
                    cout << "Success" << endl;
                    ack[i] = 1;
                    recieved[i] = sender[i];
                } else {
                    cout << "Failure " << endl;
                }
            }
            if(limit == 0) break;
        }
        cout << endl;
    }
    cout << endl;
    cout << "Recieved array " << endl;
    for(int i : recieved){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}