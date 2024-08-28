#include<bits/stdc++.h>

using namespace std;

int lowerBound(vector<int>arr,int k){
    int n = arr.size();

    int low =0 , high = n-1;
    int ans = n;

    while(low<=high){
        int mid = (low+high)/2;
        if (arr[mid] > k) {
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

/*
Operation :

It returns an iterator pointing next to the target element present or the next greater element in the array when the target is not present. If the target is greater than the largest element in the given array, it returns an iterator at the end of the array.

Syntax :

int* itr = upper_bound(itr1,itr2,target);//returning iterator

int index = upper_bound(itr1,itr2,target)-itr1;//returns index at which iterator is pointing

Code:

C++
#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr = {1,4,5,6,9,9};
    int element = 9;
    
    vector<int>::iterator itr = upper_bound(arr.begin(),arr.end(),element);//returns iterator
    int index = upper_bound(arr.begin(),arr.end(),element)-arr.begin();//returns index
    
    cout<<"Iterator: "<<itr-arr.begin()<<" Index: "<<index;
    
    return 0;
}
*/