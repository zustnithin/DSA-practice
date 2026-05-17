#include <iostream>
#include <cmath>
using namespace std;
int findNthSqrt(int n,int N){
    int low=1;
    int high=N;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(pow(mid,n)==N) return mid;
        else if(pow(mid,n)>N) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int main(){
    int n,N;
    cin >> n >> N;
    
    
    cout << findNthSqrt(n,N);
}