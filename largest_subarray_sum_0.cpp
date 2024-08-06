#include <bits/stdc++.h>

using namespace std;

int brute(vector<int> arr , int n){
    int maxi=0;
    for(int i = 0 ; i< n ; i++){

        int sum = 0;
        
        for(int j =i ; j< n ; j++){
            sum = sum + arr[j];

            if(sum ==0 ){
                maxi = max(maxi,(j-i) + 1);
            }
        }
    }
    return maxi;
}

//t.c = O(nlogn) or O(n) n = traversing array , logn for map and ,O(1) for unordered

//s.c =O(n)
int better(vector<int> arr,int n){

unordered_map<long long, int> prefixSumMap; 
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        // Calculate the prefix sum till index i
        sum += arr[i];

        // If sum is 0, update maxLen
        if (sum == 0) {
            maxLen = max(maxLen, i + 1); 
        }

        // If the prefix sum is found in the map, calculate the length of the subarray
        if (prefixSumMap.find(sum) != prefixSumMap.end()) {
            int len = i - prefixSumMap[sum];
            maxLen = max(maxLen, len); 
        } else {
            // If the prefix sum is not found, add it to the map
            prefixSumMap[sum] = i;
        }
    }

    return maxLen;

}

int main(){
    cout << "Enter size of array: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   int ans = better(arr,n);

   
    cout<<ans<<" ";
   

}
