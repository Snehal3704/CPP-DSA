#include <bits/stdc++.h>

using namespace std;

int brute(vector<int> arr, int n , int k){
    int res=0;
    int cnt=0;
    for(int i=0 ; i < n ; i++){
    int sum=0;
        for(int j=i ; j<n ; j++){
            sum = sum + arr[j];
            if(sum == k)    cnt++;   
        }
    }
    return cnt;

}

int optimal(vector<int> arr,int n , int k){
    int n = arr.size(); // size of the given array.
    map<int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
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
    int ans = optimal(arr,n,k);

    cout<<ans;



}