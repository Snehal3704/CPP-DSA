#include<bits/stdc++.h>

using namespace std;


int main(){

    int n;
    cout<<"size";
    cin>>n;

    vector<int> arr;
    bool flag =0;

    cout<<"values";

    for(int i=0 ; i< n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    for(int i = 0 ; i< n ; i++){
        if(arr[i+1] >= arr[i]){
            flag=1;
        }
        else
        flag =0;
    }
    if(flag){
        cout<<"array is sorted";
    }
    else
    cout<<"array is not sorted";
    

}