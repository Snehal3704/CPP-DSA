#include<bits/stdc++.h>

using namespace std;

// using pick and non pick method
void getsubset(vector<int> &nums, set<vector<int>> &res, int ind, int n, vector<int> temp) {
        // base case
        if (ind == n) {
            res.insert(temp);
            return;
        }

        // Include the current element
        temp.push_back(nums[ind]);
        getsubset(nums, res, ind + 1, n, temp);
        temp.pop_back();

        // Exclude the current element
        getsubset(nums, res, ind + 1, n, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array to handle duplicates
        int ind = 0;
        int n = nums.size();
        set<vector<int>> res;
        vector<int> temp;

        getsubset(nums, res, ind, n, temp);

        // Convert set to vector
        vector<vector<int>> result(res.begin(), res.end());
        return result;
    }

    int main(){
        cout<<"enter array size";
        int n;
        cin>>n ; 


        vector<int> nums;

        cout<<"enter values";
        for(int i=0 ; i< n ; i++){
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }

        vector<vector<int>> res = subsetsWithDup(nums);

        for(int i=0 ; i< res.size(); i++){

            for(int j= 0 ; j< res[i].size() ; j++){

                cout<<res[i][j] << " ";
            }
            cout<<endl;
        }
    }
