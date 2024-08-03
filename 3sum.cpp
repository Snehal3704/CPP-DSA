#include<bits/stdc++.h>

using namespace std;

// Time Complexity = (N^3)*(log(no of unique triplets))
// Space Complexity = 2*M  (M = number of unique triplets)(1 set of vectors, 1 vector of vectors)
vector<vector<int>> brute (vector<int> arr , int n){

    set<vector<int>> st;
    sort(arr.begin(),arr.end());
    

    for(int i =0 ; i< n ; i++){
        for(int j = i +1 ; j < n ; j++){
            for(int k = j+1 ; k< n ; k++){
                if(arr[i] + arr[j] + arr[k] == 0){

                    vector<int> temp = {arr[i] , arr[j] , arr[k]};
                    //sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> res(st.begin(), st.end());
    return res;

}

// Time Complexity = N*N*(log(number of triplets))
// Space Complexity = O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.

vector<vector<int>> better(vector<int> arr , int n){

     // target = 0
    int target = 0;
    set<vector<int>> st; 

    for(int i=0; i<n; i++){
        set<int> hash;
        for(int j=i+1; j<n; j++){
            int sum = arr[i] + arr[j]; 
            int need = target - sum;   // target = 0
            if(hash.find(need) != hash.end()){
                vector<int> temp = {arr[i], arr[j], need};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hash.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;

}

// Time Complexity = O(NlogN)+O(N*N)
// Space Complexity = O(number of triplets)
vector<vector<int>> optimal(vector<int> arr , int n){
    vector<vector<int>> ans;

    sort (arr.begin() ,arr.end());


    for(int i=0 ; i< n ; i++){
        int j= i+1;
        int k = n -1;

        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}

int main(){
    cout<<"enter the size";
    int n ;
    cin>>n;

    cout<<"enter the values";
    vector<int> arr;

    for(int i= 0 ; i< n ; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    vector<vector<int>> ans = better(arr,n);

    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
}