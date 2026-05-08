#include <iostream>
#include <string>
#include <cctype>
bool isAlreadysigned=false;
bool isAlreadystarted=false;
using namespace std;
void atoii(int i,const string &s){
    if(i>=s.length()){
        return;
    }
    if(s[i]==' '){
        atoii(i+1,s);
        return;
    }
    if(s[i]=='+' || s[i]=='-'){
        if(isAlreadysigned || isAlreadystarted){
            return;
        }
        cout << s[i];
        isAlreadysigned=true;
    }
    else if(isdigit((unsigned char)s[i])){
        cout << s[i];
        isAlreadystarted=true;
    }
    
    else{
        return;
    }
    atoii(i+1,s);
}
int main(){
    string s;
    getline(cin,s);
    atoii(0,s);
}