#include <iostream>
using namespace std;
int findPeaks(int arr[],int n){
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return 0;
    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid-1]<arr[mid]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << arr[findPeaks(arr,n)];
}