#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool isPossibleOrNot(int arr[],int n,int m,int k,int day){
    int onecount=0;int concount=0;
    if(m*k>n) return false;
    else{
        
        for(int i=0;i<n;i++){
            if(arr[i]<=day){
                onecount++;
            }
            else{
                onecount=0;
            }
            if(onecount==k){
                onecount=0;
                concount++;
            }
        }
        if(concount>=m){
            return true;
        }
    }
    return false;
}

int findingMinDays(int arr[],int n,int m,int k){
    int low=1;
    int high=*max_element(arr,arr+n);
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isPossibleOrNot(arr,n,m,k,mid)){
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
    int n,m,k;
    cin >> n >> m >> k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << findingMinDays(arr,n,m,k);
}