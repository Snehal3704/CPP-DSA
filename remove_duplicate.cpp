#include<bits/stdc++.h>

using namespace std;

int main(){
    // int n;
    // vector<int> arr;
    // vector<int> res;

    // cout<<"size";
    // cin>> n;

    // cout<<"values in sorted order";

    // for(int i= 0; i< n ; i++){
    //     int temp;
    //     cin >> temp;
    //     arr.push_back(temp);
    // }

    // for(int i=0 ; i < n ; i++){
    //     if(res.empty() || res.back() != arr[i]){
    //         res.push_back(arr[i]);
    //     }
    // }

    

    // for(int i= 0 ; i<res.size() ; i++){

    //     arr[i] = res[i]; 
    //     cout<<arr[i] <<" ";  
    // }

    // using set

    set<int> st;

    int n;
    vector<int> arr;
    vector<int> res;

    cout<<"size";
    cin>> n;

    cout<<"values in sorted order";

    for(int i= 0; i< n ; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for(int i = 0 ; i< n ; i++){
        st.insert(arr[i]);
    }

    int ind =0;
    for(auto it : st){
        arr[ind] =it;
        ind++;
    }
    
    for(int i=0 ; i< st.size() ; i++){
        cout<<arr[i] << " ";
    }

    //t.c = O(nlogn) + N
    //s.c = O(n)
    


}