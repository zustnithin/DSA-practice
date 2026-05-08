#include <iostream>
#include <iomanip>
using namespace std;
double pow(double x,double n){
    if(n==0)return 1;
    else if(n>0){
        return x*pow(x,n-1);
    }
    else{
        return (1/x)*pow(x,n+1);
    }
}
int main(){
    double x,n;
    cin >> x >> n;
    cout << fixed << setprecision(4) << pow(x,n);
}