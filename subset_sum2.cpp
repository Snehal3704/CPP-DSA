#include <bits/stdc++.h>

using namespace std;

void getSubsets(vector<int> &arr, vector<int> &temp, int ind, int size, vector<vector<int>> &res) {
    for(int i = ind ; i<= arr.size() ; i++){
        if (i > ind && arr[i] == arr[i - 1]) {
            continue;
        }
        if (i == size) {
        res.push_back(temp);
        }
        temp.push_back(arr[i]);
        getSubsets(arr, temp, i + 1, size, res);
        temp.pop_back();

    }
 
}

int main() {
  int size;
  vector<int> arr;

  cout << "Enter size: ";
  cin >> size;

  cout << "Enter values: ";
  for (int i = 0; i < size; i++) {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }

  vector<int> temp;
  vector<vector<int>> res;

  sort(arr.begin(), arr.end());

  getSubsets(arr, temp, 0, size, res);

  cout << "Subsets: \n";
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
