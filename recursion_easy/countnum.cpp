#include <iostream>
#include <string>
using namespace std;
int cgn(int size,int i){
    if(i>=size) {
        return 1;
    }
    if(i%2==0){
        return 5*cgn(size,i+1);
    }
    else{
        return 4*cgn(size,i+1);
    }
}
int main(){
    int s;
    cin >> s;
    if(cgn(s,0)>1000000007){
        cout << cgn(s,0)%1000000007;
    }
    else
    cout << cgn(s,0);
}