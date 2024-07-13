#include <bits/stdc++.h>
using namespace std;

vector<int> bruteforce(vector<int> arr, int target, int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}

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
    vector<pair<int, int>> indexed_arr(n);
    for (int i = 0; i < n; i++) {
        indexed_arr[i] = {arr[i], i};
    }
    sort(indexed_arr.begin(), indexed_arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = indexed_arr[left].first + indexed_arr[right].first;
        if (sum == target) {
            return {indexed_arr[left].second, indexed_arr[right].second};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};  // Return an empty vector if no pair is found
}

int main() {
    cout << "Enter n: ";
    int n;
    cin >> n;

    cout << "Enter values: ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target: ";
    int target;
    cin >> target;

    vector<int> ans;

    cout << "Brute Force: ";
    ans = bruteforce(arr, target, n);
    if (!ans.empty()) {
        for (auto it : ans) {
            cout << it << " ";
        }
    } else {
        cout << "No pair found.";
    }
    cout << endl;

    cout << "Better: ";
    ans = better(arr, target, n);
    if (!ans.empty()) {
        for (auto it : ans) {
            cout << it << " ";
        }
    } else {
        cout << "No pair found.";
    }
    cout << endl;

    cout << "Optimal: ";
    ans = optimal(arr, target, n);
    if (!ans.empty()) {
        for (auto it : ans) {
            cout << it << " ";
        }
    } else {
        cout << "No pair found.";
    }
    cout << endl;

    return 0;
}
