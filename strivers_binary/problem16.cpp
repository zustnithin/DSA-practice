#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int findingCeilSum(int arr[],int n,int k){
    int sum=0;
    for(int i=0;i<n;i++){
        sum += ceil((double)arr[i]/k);
    }
    return sum;
}

int findingMinHours(int arr[],int n,int h){
    int low=1;
    int high=*max_element(arr,arr+n);
    int ans=-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        
        if(findingCeilSum(arr,n,mid)<=h){
            high=mid-1;
            ans=mid;
        }
        else low=mid+1; 
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
    int h;
    cin >> h;
    cout << findingMinHours(arr,n,h);
}