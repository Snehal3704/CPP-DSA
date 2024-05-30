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

    int k;
    cout<<"enter k";
    cin>>k;

    int temp[3];

    k = k % n;

    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // for(auto it : temp){
    //     cout<< it <<" ";
    // }

    for(int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    for(int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }

    for(int i=0 ; i< n ; i++){
        cout<<arr[i] << " ";
    }

}