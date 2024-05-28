#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout<<"size";
    cin>>n;

    vector<int> arr;

    cout<<"values";

    for(int i=0; i<n ; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    int first = arr[0];
    for(int i = 1 ; i< n ; i++){
        arr[i-1] =arr[i]; 
    }
    arr[n-1] = first;

    for(auto it : arr){
        cout<< it << " ";
    }
}