#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:

      vector < int > brute(vector < int > arr) {
        int n = arr.size();
        vector < int > nge(n, -1);
        for(int i = 0 ; i < n ; i++){
            for(int j = i+ 1 ; j  < n ; j++){
                if(arr[j] > arr[i]){
                    nge[i] = arr[j];
                    break;
                }
            }
        }
        return nge;
      }

      vector<int> optimal(vector<int> arr){
        stack<int> st;
        int n = arr.size();
        vector < int > nge(n, -1);

        for(int i = n - 1 ; i >= 0 ; i--){
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) nge[i] = st.top();
            st.push(arr[i]);
        }
        return nge;
      }
  };
  int main() {
    Solution obj;
    vector < int > arr {6,0,8,1,3};
    vector < int > res = obj.optimal(arr);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++) {
      cout << res[i] << " ";
    }
  }