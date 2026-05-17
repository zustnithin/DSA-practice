#include <iostream>
#include <algorithm>
using namespace std;
bool isPossibleDistance(int arr[],int n,int k,int length){
    int stationcount=0; int last=arr[0];
    for(int i=1;i<n;i++){
        if(last+length<arr[i]){
            stationcount++;
            last=last+length;
            i--;
        }
        else{
            last=arr[i];
        }
    }
    if(stationcount>=k){
        return true;
    }
    return false;
}
int MaxDistanceGasStations(int arr[],int n,int k){
    int low=0;
    int high=*max_element(arr,arr+n)-*min_element(arr,arr+n);
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isPossibleDistance(arr,n,k,mid)){
            low=mid+1;
        }
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
    cout << MaxDistanceGasStations(arr,n,k);
}