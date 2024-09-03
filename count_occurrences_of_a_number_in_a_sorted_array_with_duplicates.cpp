#include<bits/stdc++.h>

using namespace std;

//t.c=O(2logn)

int first(vector<int> arr , int k){

    int low = 0 , high = arr.size() - 1;

    int first = -1;

    while(low<=high){

    int mid = low + (high - low) / 2 ;

    if(arr[mid] == k){
        first = mid;      // eliminate right side as we need first index becuase as the array is sorted if we mid mid == k then we can definetly say maybe we can get lower value if we go to left
        high = mid - 1;
    }
    else if(arr[mid] > k){
        high = mid - 1;     // eliminate left side

    }
    else{
        low = mid +1 ;  // eliminate right half 
    }

    }

    
   return first;

}

int last(vector<int> arr , int k){

    int low = 0 , high = arr.size() - 1;

    int last = -1;

    while(low<=high){

    int mid = low + (high - low) / 2 ;

    if(arr[mid] == k){
        last = mid;      // eliminate left side
        low = mid + 1;
    }
    else if(arr[mid] > k){
        high = mid - 1;     // eliminate right side

    }
    else{
        low = mid +1 ;  // eliminate left half 
    }

    }

    /*
        if(arr[mid] >= k){
        last = mid;
        low = mid+1;
        }


    */
   return last;

}

int main(){

    
    int k = 13;
    vector < int > arr= {3,4,13,13,13,20,40};
    int ans1 = first(arr,k);
    

    if(ans1 != -1) {
    int ans = last(arr,k);  // if we dont find the key we will not waste another logn time as there will not exist a last occurence
    cout<< (ans - ans1) + 1;
    }
    
}