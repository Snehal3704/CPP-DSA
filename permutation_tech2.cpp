#include<bits/stdc++.h>
using namespace std;

void getpermutations(vector<vector<int>> &res, vector<int> &temp, vector<int> &arr, int size, int ind) {
    if (ind == size) {
        res.push_back(temp);
        return;
    }

    for (int i = ind; i < size; i++) {
        swap(arr[ind], arr[i]);
        temp.push_back(arr[ind]);
        getpermutations(res, temp, arr, size, ind + 1);
        temp.pop_back();
        swap(arr[ind], arr[i]);
    }
}

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;

    cout << "Enter values: ";
    vector<int> arr(size);

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> res;
    vector<int> temp;

    getpermutations(res, temp, arr, size, 0);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
