#include <bits/stdc++.h>
using namespace std;
class Queue{
    public:
    int queue[5];
    int start=-1;
    int end=-1;
    int size=0;
    void push(int x){
        if(start==-1&&end==-1){
            start++;
            end++;
            size++;
            queue[start]=x;
        }
        else{
            if(size<5){
                end=(end+1)%5;
                queue[end]=x;
                size++;
            }
            else{
                cout <<" queue is full "<< endl;
            }
            
        }
    }
    int pop(){
        if(size==1){
            int x = queue[start];
            start=-1;
            end=-1;
            size=0;
            return x;
        }
        else if(size==0){
            cout << " queue is empty " << endl;
        }
        else{
            int x = queue[start];
            start=(start+1)%5;
            size--;
            return x;
        }
        return -1;
    }
    bool isEmpty(){
        return size==0;
    }
};