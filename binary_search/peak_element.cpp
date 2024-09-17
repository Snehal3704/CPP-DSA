#include<bits/stdc++.h>

using namespace std;

int brute(vector<int>arr){

    int n = arr.size();

    for(int i= 0 ;i< n ; i++){
        if(arr[i] > arr[i-1] and arr[i] > arr[i+1]){
            return i;
        }
    }

    return -1;
}

//we are checking if the mid element is peak of not by arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1] this condition but for edge cases meaning for i = 0 and i = n-1 means 
//if the last and the element is peak then for mid = 0(first element) then (mid - 1) will be -1 and for mid = n-1(last element) (mid+1) will be n which is undefined so we will check thhis edge cases manually and trim the search space


int optimal(vector<int>arr){
    int n = arr.size();

    //edge cases

    if(n==1)    return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;

    int low = 1 , high = n-2;

    while(low<= high){

        int mid = (high - low) / 2 + low;

        if(arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]){
            return mid;

        }

        //if we are at left side
        //means if this below condition satisfied then we are at the increasing side of the graph meaning peak will be next of this point
        if(arr[mid] < arr[mid +1]){
            low = mid + 1;
        }

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else{
            high = mid -1 ;
        }
    }
}

int main(){

    vector<int> arr = {1,2,1,3,5,6,4};
    int ans = brute(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;

}