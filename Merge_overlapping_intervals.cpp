#include<bits/stdc++.h>
using namespace std;

// BRUTE
// Time Complexity = Nlog(N) + 2N
// Space Complexity = O(N)

void brute(vector<vector<int>> arr){
    int n = arr.size(); 
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++){

        int start = arr[i][0]; 
        int end = arr[i][1];

        if(!ans.empty() and start <= ans.back()[1]) { // if ans is non-empty 
            continue;     // and the last element of the previous pair is greater than the first element 
        }           // of the current pair or not (if yes that means that interval is already in the ans)

        for(int j=i+1; j<n; j++){

            int first = arr[j][0]; // first element of of next intervals
            int last = arr[j][1]; // last element of next intervals

            if(first <= end){
                end = max(end, last); 
            }
            else{
                break; 
            }
        }
        ans.push_back({start, end});
    }

    for(int i=0; i<ans.size(); i++){
        cout<<"{ "<<ans[i][0]<<", "<<ans[i][1]<<" }"<<" ";
    }
    cout<<endl;
}

// OPTIMAL
// Time Complexity = Nlog(N) + N
// Space Complexity = O(N)

void optimal(vector<vector<int>> arr){
    int n = arr.size(); 
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans; 

    for(int i=0; i<n; i++){

        int start = arr[i][0];
        int end = arr[i][1];

        if(!ans.empty() and start <= ans.back()[1]){
            ans.back()[1] = max(ans.back()[1], end); 
        }
        else{ 
            ans.push_back({start, end});
        }
    } 

    for(int i=0; i<ans.size(); i++){
        cout<<"{ "<<ans[i][0]<<", "<<ans[i][1]<<" }"<<" ";
    }
    cout<<endl;
}

int main (){ 
    
    vector<vector<int>> arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};  // [[1,3], [2,6]]
    
    brute(arr); 
    optimal(arr);
}