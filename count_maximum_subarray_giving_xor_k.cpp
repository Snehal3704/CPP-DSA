#include <bits/stdc++.h>

using namespace std;

int brute(vector<int> arr, int n , int k){
    
     int cnt = 0;
    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            int xorr = 0;
            for (int K = i; K <= j; K++) {
                xorr = xorr ^ arr[K];
            }

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;

}

// Time Complexity: O(N2), where N = size of the array.
// Reason: We are using two nested loops here. As each of them is running for N times, the time complexity will be approximately O(N2).

// Space Complexity: O(1) as we are not using any extra space.
int better(vector<int> arr , int n , int k){
    int cnt =0;

// Step 1: Generating subarrays:
    for(int i=0 ; i< n ; i++){
        int xorr =0;
        for(int j= i ; j < n ;j++){

            //step 2:calculate XOR of all
            // elements:
            xorr = xorr ^ arr[j];

            // step 3:check XOR and count:
            if (xorr == k) cnt++;

        }
    }
    return cnt;

}

// Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
// Space Complexity: O(N) as we are using a map data structure.

int optimal(vector<int> arr,int n , int k){
    
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ arr[i];

        //By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;

    return cnt;
}


int main(){
    cout << "enter n: ";
    int n;
    cin >> n;

    cout << "enter values: ";
    vector<int> arr(n);  

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<"enter k";
    int k;
    cin>>k;
    int ans = better(arr,n,k);

    cout<<ans;



}