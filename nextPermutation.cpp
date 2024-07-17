#include<bits/stdc++.h>

using namespace std;

void optimal(vector<int> &arr, int n){
int ind = -1;
    // Step 1: Find the break point:
    for(int i= n-2 ; i >=0 ; i++){
        if (arr[i] < arr[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(arr.begin(), arr.end());
        for(auto it: arr){
        cout<<it <<" ";
        }
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (arr[i] > arr[ind]) {
            swap(arr[i], arr[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(arr.begin() + ind + 1, arr.end());

    for(auto it: arr){
        cout<<it <<" ";
    }
    //return A;

    

}

int main() {
    cout << "Enter size of array: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //next_permutation(arr.begin() ,arr.end());
    optimal(arr,n);


}