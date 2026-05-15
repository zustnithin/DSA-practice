#include <bits/stdc++.h>
using namespace std;
class Stack{
    public:
    int st[10];
    int top=-1;

    void push(int x){
    if(top==9){
        cout << "OVERFLOW -- STACK IS FULL"<<endl;
    }
    else{
        top++;
        st[top]=x;
    }
    }   
    int pop(){
    if(top==-1){
        cout << "UNDERFLOW -- STACK IS EMPTY" << endl;
    }
    else{
        int x = st[top];
        top--;
        return x;
    }
    return -1;
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        return top==-1;
    }
};
int main(){
    Stack st;
    st.push(4);
    st.push(5);
    st.push(7);
    cout << st.pop() << st.pop() << st.pop() << st.isEmpty();
}