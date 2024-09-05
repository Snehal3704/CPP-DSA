#include<bits/stdc++.h>

using namespace std;

//with duplicate eliments

int optimal(vector<int>arr , int k){
    
    int low = 0 , high = arr.size() - 1;

    while(low <= high){

        int mid = (high - low)  / 2 + low;

        if(arr[mid] == k){
            return mid;
        }

        //checking which part is sorted
        //as we know binary search discart the other sorted half so
        // we have to identify the sorted half either it is left part or right part

        //checking if left part is sorted

        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                // if  element exists:
                high = mid - 1; //eliminate right half move left
            }
            else {
                //element does not exist:
                low = mid + 1;  // eliminate left half move right
            }
        }

        //else right part is sorted:
        else { 
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }

    return -1;

    }



int main(){
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int k = 1;
    int ans = optimal(arr,k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}
