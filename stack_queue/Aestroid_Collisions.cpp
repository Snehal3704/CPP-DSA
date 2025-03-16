#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& arr) {
            stack<int> st;
            int n = arr.size();
            
            for(int i = 0; i < n; i++) {
                if(arr[i] > 0) {
                    st.push(arr[i]); // Push positive asteroids (moving right)
                } else {
                    while(!st.empty() && st.top() > 0 && st.top() < abs(arr[i])) {
                        st.pop(); // Destroy smaller right-moving asteroids
                    }
    
                    if(!st.empty() && st.top() == abs(arr[i])) {
                        st.pop(); // Destroy both if they are of equal size
                    } else if(st.empty() || st.top() < 0) {
                        st.push(arr[i]); // Push left-moving asteroid if no collision
                    }
                }
            }
    
            vector<int> ans(st.size());
            for(int i = st.size() - 1; i >= 0; i--) {
                ans[i] = st.top(); // Extract elements in correct order
                st.pop();
            }
            
            return ans;
        }
};

int main(){

    Solution obj;
    vector<int> arr={4,7,1,1,2,-3,-7,17,15,-16,-17,-19};

    vector<int> ans = obj.asteroidCollision(arr);
    for(auto it : ans){
        cout<< it <<" ";
    }
}

    