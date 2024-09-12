#include<bits/stdc++.h>

using namespace std;

int brute(vector<int>arr){

    /*
    Edge Cases:

    If n == 1: This means the array size is 1. If the array contains only one element, we will return that element only.
    If i == 0: This means this is the very first element of the array. The only condition, we need to check is: arr[i] != arr[i+1].
    If i == n-1: This means this is the last element of the array. The only condition, we need to check is: arr[i] != arr[i-1].

    */

   int n = arr.size(); //size of the array.
    if (n == 1) return arr[0];

    for (int i = 0; i < n; i++) {

        //Check for first index:
        if (i == 0) {
            if (arr[i] != arr[i + 1])
                return arr[i];
        }
        //Check for last index:
        else if (i == n - 1) {
            if (arr[i] != arr[i - 1])
                return arr[i];
        }
        else {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                return arr[i];
        }
    }

    // dummy return statement:
    return -1;


}

int bruteUsingXor(vector<int>arr){
    /*
    We can simplify the above approach using the XOR operation. We need to remember 2 important properties of XOR:

    a ^ a = 0, XOR of two same numbers results in 0.
    a ^ 0 = a, XOR of a number with 0 always results in that number.
    */

   int n = arr.size(); //size of the array.
    int ans = 0;

    // XOR all the elements:
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

int optimal(vector<int> arr){
     int n = arr.size(); //size of the array.

    //Edge cases: as we are trimming the search space from low = 1 and high = n-2
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];    // handling with single conditions
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        //we are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            //eliminate the left half:
            low = mid + 1;
        }
        //we are in the right:
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
}



int main(){

    vector<int> arr = {1,1,2,2,3,3,4,5,5,6,6};
    int ans = optimal(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;



}