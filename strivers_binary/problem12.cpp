#include <iostream>
using namespace std;
int findSingleElement(int arr[],int n){
    int low=0;
    int high= n-1;
    if(arr[0]!=arr[1]){
        return 0;
    }
    if(arr[n-1]!=arr[n-2]){
        return n-1;
    }
    low++;
    high--;

    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            return mid;
        }
        if(arr[mid]==arr[mid-1]){
            if(mid%2!=0){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        if(arr[mid]==arr[mid+1]){
            if(mid%2==0){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
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
    cout << arr[findSingleElement(arr,n)];
}