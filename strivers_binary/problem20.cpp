#include <iostream>
#include <algorithm>
using namespace std;
int getKthMissing(int arr[],int n,int k){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if((arr[mid]-mid-1)<k) low=mid+1;
        else high=mid-1;
    }
    return k+low;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << getKthMissing(arr,n,k);
}