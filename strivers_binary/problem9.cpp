#include <iostream>
using namespace std;
int searchInRotatedArray(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==target) return mid;
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++;high--;
            continue;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=target && target <=arr[high]){
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
    //enter a sorted array
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << searchInRotatedArray(arr,n,target) << endl;
}