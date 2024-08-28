#include<bits/stdc++.h>

using namespace std;

int lowerBound(vector<int>arr,int k){
    int n = arr.size();

    int low =0 , high = n-1;
    int ans = n;

    while(low<=high){
        int mid = (low+high)/2;
        if (arr[mid] >= k) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, k = 9;
    int ind = lowerBound(arr,k);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}

// Some other stl functions on binary search:
// Lower Bound
// Operation :

// It returns an iterator. If the element is present, returns an iterator for its first occurrence. If not, return the iterator for its next greater element in the array. When the element is not present in the array and greater than the largest element present in the array then the iterator returned is outside the array.

// Syntax :

// int* itr = lower_bound(itr1,itr2,element);//returning iterator

// int index = lower_bound(itr1,itr2,element)-itr1;//returns index at which iterator is pointing

// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     vector<int> arr = {1,4,5,6,9,9};
//     int element = 9;
    
//     vector<int>::iterator itr = lower_bound(arr.begin(),arr.end(),element);//returns iterator
//     int index = lower_bound(arr.begin(),arr.end(),element)-arr.begin();//returns index
    
//     cout<<"Iterator: "<<itr-arr.begin()<<" Index: "<<index;
    
//     return 0;
// }
