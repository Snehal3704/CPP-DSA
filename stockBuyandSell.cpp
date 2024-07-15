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

 int maxProfit(vector<int>prices) {
        int maxP = 0, left= 0, right = 0;
        while (right < prices.size()){
            if (prices[right] > prices[left])
                maxP = max(maxP, prices[right] - prices[left]);
            else
                left= right;
            ++right;
        }
        return maxP;
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

    int maxprofit = brute(arr,n);

    cout<<maxprofit;



}