#include<bits/stdc++.h>

using namespace std;

int iterative(vector<int> arr,int k, int n){
    int low =0 , high = n-1;

    while(low<=high){

    int mid = (high - low) /2 + low;

    if(arr[mid] == k)   return mid;

    else if(arr[mid] < k)   low = mid + 1;

    else
        high = mid - 1 ;

    }

    return -1;
}

int recursive(vector<int>arr,int k ,int low ,int high){

    int mid = (high - low) /2 + low ;

    if(arr[mid] == k)   return mid;

    else if(arr[mid] < k)   return recursive(arr,k , mid+1 , high);

    else    return recursive(arr,k,low,mid - 1);

     
}

int get_index(vector<int>arr,int k,int n){

     return recursive(arr,k,0,arr.size()-1);
}

int main(){

    vector<int> arr ={3,5,6,7,9,10,13,15,16};

    int n = arr.size();

    int k= 16;
    int ans = get_index(arr,k,n);
    cout<<ans;
    return 0;

}