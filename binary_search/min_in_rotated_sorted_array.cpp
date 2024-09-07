#include<bits/stdc++.h>

using namespace std;

//Key Observation: If an array is rotated and sorted, we already know that for every index, one of the 2 halves of the array will always be sorted.
//our main goal is to good binary search such a way that we can identify the sorted half

// we  see that the pivot point the lowest so 
//after that we are sure that the sorted half may or maynot have the element 
//so we will take the min of the sorted part(low for left sorted array and mid for right) and discard the sorted by that we are eliminating the possibility if the sorted part have the answer
//we canot eliminate the unsorted part as it may have the asnwer


// after that we check for thw non sorted part

int optimal(vector<int>arr){
    
    int low = 0 , high = arr.size() - 1;
    int ans = INT_MAX;

    while(low <= high){

        int mid = (low + high ) / 2;

        //if left part is sorted

        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }

        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }

    return ans;
    
}

int findMin(vector<int> arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}
int main(){

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = optimal(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;

}