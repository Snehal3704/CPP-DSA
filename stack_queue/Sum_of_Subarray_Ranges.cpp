#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long brute(vector<int> arr) {
            int n = arr.size();
            long long sum = 0;
            for(int i=0;i<n;i++){
                long long maxi = arr[i];
                long long mini = arr[i];
                for(int j=i;j<n;j++){
                    maxi = max(maxi,(long long)arr[j]);       // take care of type casting here
                    mini = min(mini,(long long)arr[j]);
                    sum += maxi - mini;
                }
            }
            return sum;
        }

                vector<int> NextSmaller(const vector<int>& arr) {
                    int n = arr.size();
                    vector<int> nextSmall(n, n); // Initialize with n
                    stack<int> stk;
                    for (int i = n - 1; i >= 0; i--) {
                        while (!stk.empty() && arr[i] <= arr[stk.top()])
                            stk.pop();
                        if (!stk.empty()) nextSmall[i] = stk.top();
                        stk.push(i);
                    }
                    return nextSmall;
                }
            
                vector<int> PrevSmaller(const vector<int>& arr) {
                    int n = arr.size();
                    vector<int> prevSmall(n, -1); // Initialize with -1
                    stack<int> stk;
                    for (int i = 0; i < n; i++) {
                        while (!stk.empty() && arr[i] < arr[stk.top()])
                            stk.pop();
                        if (!stk.empty()) prevSmall[i] = stk.top();
                        stk.push(i);
                    }
                    return prevSmall;
                }
            
                long long sumSubarrayMins(vector<int>& arr) {
                    vector<int> pse = PrevSmaller(arr);
                    vector<int> nse = NextSmaller(arr);
                    long long total = 0;
                    for (int i = 0; i < arr.size(); i++) {
                        int left = (pse[i] == -1) ? (i + 1) : (i - pse[i]);
                        int right = (nse[i] == arr.size()) ? (arr.size() - i) : (nse[i] - i);
                        total = (total + (left * right * 1LL * arr[i]));
                    }
                    return total;
                }
            
                vector<int> nextLargerElement(vector<int>& arr) {
                    int n = arr.size();
                    vector<int> ans(n, n);
                    stack<int> st;
                    for (int i = n - 1; i >= 0; i--) {
                        while (!st.empty() && arr[st.top()] <= arr[i])
                            st.pop();
                        if (!st.empty()) ans[i] = st.top();
                        st.push(i);
                    }
                    return ans;
                }
            
                vector<int> previousLargerElement(vector<int>& arr) {
                    int n = arr.size();
                    vector<int> ans(n, -1);
                    stack<int> st;
                    for (int i = 0; i < n; i++) {
                        while (!st.empty() && arr[st.top()] < arr[i])
                            st.pop();
                        if (!st.empty()) ans[i] = st.top();
                        st.push(i);
                    }
                    return ans;
                }
            
                long long sumSubarrayMax(vector<int>& arr) {
                    vector<int> pse = previousLargerElement(arr);
                    vector<int> nse = nextLargerElement(arr);
                    long long total = 0;
                    for (int i = 0; i < arr.size(); i++) {
                        int left = (pse[i] == -1) ? (i + 1) : (i - pse[i]);
                        int right = (nse[i] == arr.size()) ? (arr.size() - i) : (nse[i] - i);
                        total = (total + (left * right * 1LL * arr[i]));
                    }
                    return total;
                }
            
                long long subArrayRanges(vector<int>& nums) {
                    return (sumSubarrayMax(nums) - sumSubarrayMins(nums));
                }
};



int main(){
    Solution obj;
    vector<int> arr = {1,2,3};

    cout<<  obj.subArrayRanges(arr);

}