#include <bits/stdc++.h>

using namespace std;

int brute(vector<int> arr , int n){
    int maxi=0;
    for(int i=0 ; i< n ; i++){
        for(int j=i+1 ; j<n ; j++){

            if(arr[j] > arr[i]){
                int profit = arr[j] - arr[i];
                maxi = max(maxi,profit);
            }
        }
    }
    return maxi;

}

 int maxProfit(vector<int>arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    // cout<<minPrice<<endl;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        // cout<<i <<"th"<<endl;
        // cout<<minPrice <<endl;

        maxPro = max(maxPro, arr[i] - minPrice);
        // cout<<maxPro << endl;
    }
    
    return maxPro;
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
    
    int maxprofit = maxProfit(arr);
    cout<<"final ans";
    cout<<maxprofit;



}
