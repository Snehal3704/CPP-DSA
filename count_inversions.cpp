#include<bits/stdc++.h>

using namespace std;

//t.c=O(n2)
//s.c =O(1)
vector<vector<int>> brute(vector<int> arr){
    vector<vector<int>> ans;
    int cnt =0;
    for(int i= 0 ;i< arr.size() ; i++){
        for(int j = i+1 ; j<arr.size();j++){
            if(arr[i] > arr[j]) {
                cnt++;
                
                ans.push_back({arr[i],arr[j]});
            }
        }
    }
    return ans;
}

// OPTIMAL

// Time Complexity = O( N*log(N) )
// Space Complexity = O(N)

int merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp; 
    int left = low;
    int right = mid+1;

    int cnt = 0; 

    while(left <= mid and right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++; 
            cnt = cnt + mid - left + 1;  // lenght of the left array form 'left' pointer to 'mid'
        }   // counts the number of elements in the left arry that can make inverse pairs with the each right element                  
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++; 
    }
    while(right <= high){
        temp.push_back(arr[right]); 
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low]; 
    }
    return cnt ; 
}
int mergesort(vector<int> &arr, int low, int high){
    int cnt = 0; 
    if(low >= high) return  cnt; 
    int mid = (low+high)/2;
    cnt = cnt + mergesort(arr, low, mid); // it will go to some depth and its rplaced by 'cnt' through counting function in follow up depth in a tree and sort 
    cnt = cnt + mergesort(arr, mid+1, high); // same for this
    cnt = cnt + merge(arr, low, mid, high); // counts when merging by comparing elements from right and left array 
    return cnt; 
}


int main(){

    vector<int> arr = {5, 4, 3, 2, 1};
    int n = 5;
    // vector<vector<int>> res = brute(arr);

    // int cnt = res.size();
    // cout<<cnt<<" "<<endl;

    // for(auto it: res){
    //     for(auto xd : it){
    //         cout<< xd <<" ";
    //     }
    //     cout<<endl;
    // }

    int ans =mergesort(arr,0,n-1);

    cout<<ans;

    return 0;
}