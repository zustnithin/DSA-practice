#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;
bool isPossibleOrNot(int arr[],int n,int days,int capacity){
    if(capacity<*max_element(arr,arr+n)) return false;
    int count=0;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+arr[i]<=capacity){
            sum+=arr[i];
        }
        else{
            count++;
            sum=arr[i];
        }
        
    }
    if(sum>0){count++;}
    if(count>days){ return false;}
    return true;
}

int findingMinCapacity(int arr[],int n,int days){
    int low=*max_element(arr,arr+n);
    int high=accumulate(arr,arr+n,0);
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isPossibleOrNot(arr,n,days,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

    
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int days;
    cin >> days;
    cout << findingMinCapacity(arr,n,days);
}