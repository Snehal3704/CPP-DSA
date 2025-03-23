#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getNSL(vector<int> arr, int n) {
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

    vector<int> getNSR(vector<int> arr, int n) {
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

    int two_pass(vector<int>& arr) {
    vector<int> NSL = getNSL(arr,arr.size());
    vector<int> NSR = getNSR(arr,arr.size());
    int maxi = INT_MIN;

    for(int i = 0 ; i< arr.size() ; i++){

        int left = NSL[i] + 1;
        int right = NSR[i] -1;

        int area = (right - left + 1)   * arr[i];
        maxi = max(maxi,area);
    }
    return maxi;

    }
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;  
        int maxArea = 0;
        int n = arr.size();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] > arr[i])) {
                int height = arr[st.top()];
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                int width = i - pse - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> histogram = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(histogram) << endl;
    return 0;
}
