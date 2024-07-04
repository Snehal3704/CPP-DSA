#include <bits/stdc++.h>

using namespace std;

int main(){
    int n1;
    cout << "size of 1st array: ";
    cin >> n1;

    vector<int> arr1;
    vector<int> arr2;

    cout << "values of 1st array: ";

    for(int i = 0; i < n1; i++){
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

    int i=0,j=0;
    vector<int> ans;

    while(i < n1 and j < n2){
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr2[j] < arr1[i]){
            j++;
        }
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    for(auto it :ans){
        cout<<it <<" ";
    }

}