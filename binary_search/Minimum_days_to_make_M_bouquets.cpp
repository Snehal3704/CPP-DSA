#include<bits/stdc++.h>

using namespace std;

int isPossible(int mid , int m , int k,vector<int>arr){
    int cnt =0;
    int maxi=0;

    for(int i=0 ; i<arr.size();i++){

        if(arr[i] <= mid){
            cnt++;
        }

        else{
            cnt=0;
        }

        if(cnt == k){
            maxi++;
            cnt=0;
        }
        
    }

    if(maxi >= m)   return true;
    else  return false;

}

int optimal(vector<int> arr, int k , int m){

    int low = *min_element(arr.begin(),arr.end());
    int high = *max_element(arr.begin(),arr.end());

    while( low <= high){

        int mid = (low + high)  >> 1;

        if(isPossible(mid,m,k,arr)){
            high = mid -1;
        }
        else{
            low = mid +1;
        }

    }
    
    if(isPossible(low,m,k,arr)) return low;
    else return -1;
}

int main(){

    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = optimal(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    
    return 0;
}
