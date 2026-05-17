#include <iostream>
#include <algorithm>
using namespace std;
bool isPossibleDistance(int arr[],int n,int k,int length){
    int cowscount=1; int last=0;
    for(int i=0;i<n;i++){
        if(arr[i]-last>=length){
            cowscount++;
            last=arr[i];
        }
    }
    if(cowscount>=k) return true;

    return false;
}
int MinMaxCowsDistance(int arr[],int n,int k){
    int low=*min_element(arr,arr+n);
    int high=*max_element(arr,arr+n)-*min_element(arr,arr+n);
    
    while(low<=high){
        int mid = low+(high-low)/2;
        if(isPossibleDistance(arr,n,k,mid)){ low=mid+1;}
        else high=mid-1;
    }
    return high;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int k;
    cin >> k;
    cout << MinMaxCowsDistance(arr,n,k);
}