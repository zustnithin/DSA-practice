#include <iostream>
using namespace std;
int bs(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    //enter a sorted array
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << bs(arr,n,target);
}