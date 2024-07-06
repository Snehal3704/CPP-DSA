#include <bits/stdc++.h>

using namespace std;

int usinghash(vector<int> arr, int n , int ans){
    //t.c=O(3n)
    int maxi =0;
    for(int i=0 ; i< n ; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }

    vector<int> hash(maxi+1,0);

    for(int i =0 ; i< n ; i++){
        hash[arr[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1)
             return arr[i];
    }

return -1;//for only single element array 
}

int usingMap(vector<int> arr , int n){

    unordered_map<int,int> mpp;
    for(int i=0 ; i< n ;i++){
        mpp[arr[i]]++;  //nlongm = n size of array and m size of map
    }

    for (auto it : mpp) {   //second == frequency , first = element
        if (it.second == 1)
            return it.first;
    }
}

int usingXor(vector<int> arr,int n){
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int main(){

    int n;
    cout<<"enter n";
    cin>>n;

    vector<int>arr;
    int ans;

    
    //{4, 1, 2, 1, 2}
    cout<<"enter the n elements";
    for(int i=0; i<n ; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    ans = usingXor(arr,n);
    cout<<ans;
    
    return 0;
}
