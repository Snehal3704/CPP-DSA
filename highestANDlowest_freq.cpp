#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "size: ";
    cin >> n;

    vector<int> arr(n);
    unordered_map<int, int> mpp;

    cout << "values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mpp[arr[i]]++;
    }

    int highest_freq_cnt = 0;
    int highest_freq_ele = 0;
    int lowest_freq_cnt = INT_MAX;
    int lowest_freq_ele = 0;

    for (auto it : mpp) {
        if (it.second > highest_freq_cnt) {
            highest_freq_cnt = it.second;
            highest_freq_ele = it.first;
        }

        if (it.second < lowest_freq_cnt or (it.second == lowest_freq_cnt and it.first < lowest_freq_ele)) {
            lowest_freq_cnt = it.second;
            lowest_freq_ele = it.first;
        }
    }

    cout << "The highest frequency element is: " << highest_freq_ele <<" \n";
    cout << "The lowest frequency element is: " << lowest_freq_ele <<"\n";

    return 0;
}
