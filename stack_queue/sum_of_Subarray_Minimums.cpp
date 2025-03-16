#include <bits/stdc++.h>

using namespace std;


typedef unsigned long long ll;
class Solution {
    public:
    
    int brute(vector<int> arr) {
        int n = arr.size();
        int sum = 0;
    
        for(int i = 0 ; i < n ; i++){
    
        int mini = INT_MAX;
    
        for(int j = i ; j < n ; j++){
            mini = min(mini,arr[j]);
            sum = sum + mini;
        }
        
        }
    
    return sum;
    }
    //This is just we are finding next smaller to each element to left
    //Similar : Leetcode-84
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] > arr[i]) //strictly less
                    st.pop();
                
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    //This is just we are finding next smaller to each element to right
    //Similar : Leetcode-84
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) //non-strictly less
                    st.pop();
                
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> NSL = getNSL(arr, n); //Next smaller to left
        vector<int> NSR = getNSR(arr, n); //Next smaller to right
        
        
        ll sum = 0;
        int M = 1e9+7;
        for(int i = 0; i<n; i++) {
            ll d1 = i - NSL[i]; //distance to nearest smaller to left from i
            
            ll d2 = NSR[i] - i; //distance to nearest smaller to right from i
            
            /*
                we have d1 numbers in the left and d2 numbers in the right
                i.e. We have d1 options to start from the left of arr[i] 
                and d2 options to end in the right of arr[i]
                so the total options to start and end are d1*d2
            */
            //total subarrays of having i as min
            ll total_ways_for_i_min = d1*d2;
            ll sum_i_in_total_ways  = arr[i] * (total_ways_for_i_min);
            
            sum  = (sum + sum_i_in_total_ways)%M;
        }
        
        return sum;
        
    }
};


int main() {
    Solution obj;
    vector<int> arr = {3, 1, 2, 4};

    int x = obj.sumSubarrayMins(arr);
    cout << x << endl; // Print output with newline

    return 0;
}
