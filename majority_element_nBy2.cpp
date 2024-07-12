#include <bits/stdc++.h>

using namespace std;

int Moores_Voting_Algorithm(vector<int> &arr, int n) {
    int cnt = 0, ele = 0;

    // Phase 1: Find the candidate for majority element
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            ele = arr[i];
            cnt = 1;
        } else if (arr[i] == ele) {
            cnt++;
        } else {
            cnt--;  //// this final value of cnt does not represent anything
        }
    }

    ////do this step if it says the array might not have majority element
    // Phase 2: Verify if the candidate is actually the majority element
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == ele) {
            cnt1++;
        }
    }

    if (cnt1 > n / 2) {
        return ele;
    }

    return -1; // No majority element found
}

int better(vector<int> &arr, int n) {
    // Declaring a map to store the frequency of elements
    map<int, int> mpp;

    // Storing the elements with their occurrences
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    // Searching for the majority element
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }

    return -1; // No majority element found
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

    int ans = Moores_Voting_Algorithm(arr, n);
    if (ans != -1) {
        cout << "Majority element (Moore's Voting Algorithm): " << ans << endl;
    } else {
        cout << "No majority element found (Moore's Voting Algorithm)" << endl;
    }

    ans = better(arr, n);
    if (ans != -1) {
        cout << "Majority element (Better approach): " << ans << endl;
    } else {
        cout << "No majority element found (Better approach)" << endl;
    }

    return 0;
}
