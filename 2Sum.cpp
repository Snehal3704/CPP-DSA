#include <bits/stdc++.h>
using namespace std;


// BRUTE
// Using two Loops

// Time Complexity = O(n^2)
// Space Complexity = O(1)
vector<int> bruteforce(vector<int> arr, int target, int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;  // Return immediately when a pair is found
            }
        }
    }
    return ans;
}

// BETTER
// Using Maps/Hashing

/* Time Complexity = In the worst case(which rarely happens), 
the unordered_map takes O(N) to find an element. 
In that case, the time complexity will be O(N2). 
If we use map instead of unordered_map, the time complexity will be O(N* logN) 
as the map data structure takes logN time to find an element. */

// Space Complexity = O(n)

vector<int> better(vector<int> arr, int target, int n) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int remainder = target - arr[i];
        if (mpp.find(remainder) != mpp.end()) {
            return {mpp[remainder], i};
        }
        mpp[arr[i]] = i;
    }
    return {};  // Return an empty vector if no pair is found
}


vector<int> optimal(vector<int> arr, int target, int n) {
    vector<int> ans;
    sort(arr.begin(),arr.end());

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            ans.push_back(left);
            ans.push_back(right); 
            return ans;  

        } else if (sum > target) {
            right--;
        } else {
            left++;
        }
    }
}

int main() {
    cout << "enter n: ";
    int n;
    cin >> n;

    cout << "enter values: ";
    vector<int> arr(n);  // Properly initialize the vector

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "enter the target: ";
    int target;
    cin >> target;

    // vector<int> ans = bruteforce(arr, target, n);
    // for (auto it : ans) {
    //     cout << it << " ";
    // }
    // cout << endl;

    // vector<int> ans = better(arr, target, n);
    // for (auto it : ans) {
    //     cout << it << " ";
    // }
    // cout << endl;

    vector<int> ans = optimal(arr, target, n);  // Corrected call to optimal
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
