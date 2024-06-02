#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout << "size of 1st array: ";
    cin >> n;

    vector<int> arr1;
    vector<int> arr2;

    cout << "values of 1st array: ";

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr1.push_back(temp);
    }

    cout << "size of 2nd array: ";
    cin >> n;

    cout << "values of 2nd array: ";

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr2.push_back(temp);
    }

    map<int, int> mpp;
    vector<int> res;

    for(int i = 0; i < arr1.size(); i++){
        if(mpp[arr1[i]] == 0){
            mpp[arr1[i]]++;
            res.push_back(arr1[i]);
        }
    }

    for(int i = 0; i < arr2.size(); i++){
        if(mpp[arr2[i]] == 0){
            mpp[arr2[i]]++;
            res.push_back(arr2[i]);
        }
    }

    for(auto it : res){
        cout << it << " ";
    }

    return 0;
}
