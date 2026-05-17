#include <iostream>
#include <climits>
using namespace std;
int findMin(int arr[],int n){
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    int index=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[low]<=arr[high]){
            ans=min(ans,arr[low]);
            index=low;
            break;
        }
        if(arr[low]<=arr[mid]){
            if(ans>=arr[low]){
                ans=arr[low];
                index=low;
            }
            low=mid+1;
        }
        else{
            if(ans>=arr[mid]){
                ans=arr[mid];
                index=mid;
            }
            high=mid-1;
        }
    }
    return index;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << findMin(arr,n);
}