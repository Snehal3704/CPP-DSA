#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cout<<"size";
    cin>>n;

    vector<int> arr;
    unordered_map<int,int> mpp;

    cout<<"values";

    for(int i=0 ; i< n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int highest_feq_cnt=0;
    int highest_fre=0;

    for(int i = 0 ; i< n ; i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]] > highest_feq_cnt)
        highest_feq_cnt = mpp[arr[i]];
    }

    for( auto it : mpp){
        if(it.second == highest_feq_cnt){
            highest_fre = it.first;
        }
    }

    cout<<highest_feq_cnt;
    cout<< endl;
    cout<<highest_fre;


}