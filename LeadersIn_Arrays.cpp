#include<bits/stdc++.h>

using namespace std;

vector<int> brute(vector<int> arr,int n){
    vector<int> ans;
    for(int i =0 ; i< n ; i++){
        bool leader = true;
         //Checking whether arr[i] is greater than all 
    //the elements in its right side using liner search
        for(int j=i+1 ; i<n ; i++){
            if(arr[j] > arr[i] ){
            // If any element found is greater than current leader
            // curr element is not the leader.
            leader = false;
            break;
            }
        }
    if (leader)
    ans.push_back(arr[i]);
    }
     // Push all the leaders in ans array.

  return ans;
  }

  vector<int> optimal(vector<int> arr, int n){

    vector<int> ans;
    int maxi =INT_MIN;
    for(int i=n-1 ; i>=0; i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(arr[i] , maxi);
    }

    sort(ans.begin(),ans.end());

    return ans;
  }
  



int main() {
    cout << "Enter size of array: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   vector<int> ans = brute(arr,n);

   for(auto it: ans){
    cout<<it <<" ";
   }


}