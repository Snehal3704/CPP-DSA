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
    int n2;
    cin >> n2;

    cout << "values of 2nd array: ";

    for(int i = 0; i < n2; i++){
        int temp;
        cin >> temp;
        arr2.push_back(temp);
    }

    int visited[n2] ={0};
    vector<int> ans;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j< n2 ; j++){
            if(arr1[i] == arr2[j] && visited[j] == 0){
                ans.push_back(arr1[i]);
                visited[j] = 1;
                break;
            }
            if(arr2[j] > arr1[i]){
                break;
            }
        }
    }

    for(auto it: ans){
        cout << it << " ";
    }
}
