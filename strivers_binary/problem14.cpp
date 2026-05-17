#include <iostream>
using namespace std;
int findSqrt(int n){
    int low=1;
    int high=n;
    int ans=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid*mid>n) high = mid-1;
        else{
            ans=mid;
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    
    
    cout << findSqrt(n);
}