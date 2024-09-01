#include<bits/stdc++.h>

using namespace std;

int optimal(vector<int>arr, int k ,int n){

    int ans=n;

    int low= 0 , high = n-1;

    while(low<=high){
        int mid = (high - low)/2 + low;

        if(arr[mid] >= k){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){

    vector<int> arr ={3,5,6,7,9,10,13,15,16};

    int n = arr.size();

    int k= 17;
    int ans = optimal(arr,k,n);
    cout<<ans;
    return 0;   

}