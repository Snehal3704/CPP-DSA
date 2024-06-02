#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cout<<"size of 1st array";
    cin>>n;

    vector<int> arr1;
    vector<int> arr2;
    

    cout<<"values of 1st array";

    for(int i=0; i<n ; i++){
        int temp;
        cin>>temp;
        arr1.push_back(temp);
    }

    cout<<"size of 2nd array";
    cin>>n;

    cout<<"values of 2nd array";

    for(int i=0; i<n ; i++){
        int temp;
        cin>>temp;
        arr2.push_back(temp);
    }

    

    set<int> st;

    for(int i = 0 ; i< arr1.size() ; i++ ){
        st.insert(arr1[i]);
    }

    for(int i = 0 ; i< arr2.size() ; i++ ){
        st.insert(arr2[i]);
    }

    int size = st.size();

    vector<int> res(st.begin(), st.end()); // Changed: Initialize res with elements from the set
    
    // int i=0;

    // for (auto it : st){
    //    res[i++] = it;

    // }

    for(auto it : res){
        cout<< it <<" ";
    }

    return 0;
}