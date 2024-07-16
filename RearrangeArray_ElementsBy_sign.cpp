#include <bits/stdc++.h>

using namespace std;

//varity 2
//if the no of positive and negetives are not told equal
void varityTwo(vector<int> arr, int n){

    vector<int> pos;
    vector<int> neg;

    for(int i=0 ; i< n ; i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else
            neg.push_back(arr[i]);
    }

    if(pos.size() > neg.size()){

        for(int i=0 ; i< neg.size() ; i++){
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];
        }

        int index = neg.size() * 2 ;
        for(int i = neg.size() ; i< pos.size() ; i++){
            arr[index] = pos[i] ;
            index++;
        }
    }
    else{

        for(int i=0 ; i< pos.size() ; i++){
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];
        }

        int index = pos.size() * 2 ;
        for(int i = pos.size() ; i< neg.size() ; i++){
            arr[index] = neg[i] ;
            index++;
        }

    }

    for(auto it : arr){
        cout<<it <<" ";
    }
}

void brute(vector<int> arr , int n){
vector<int> pos;
vector<int> neg;

    for(int i=0 ; i< n ; i++){
        if(arr[i] >0)   pos.push_back(arr[i]);

        else            neg.push_back(arr[i]);
    }
    int j=0;
    int k=0;
    for(int i=0 ; i< n ; i++){
        if(i % 2 == 0){
            arr[i] = pos[k];
            k++;
        }
        else{
            arr[i] = neg[j];
            j++;
        }
        
    }

    for(auto it : arr){
        cout<<it <<" ";
    }
    

}

void better(vector<int> arr, int n){

    int pos =0 ; 
    int neg = 1;
    vector<int> ans;

    for(int i= 0 ; i< n ; i++){
        if(arr[i] < 0){
            ans[neg] = arr[i];
            neg = neg+2;
        }
        else{
            ans[pos] = arr[i];
            pos = pos +2;
        }
    }

    for(auto it : ans){
        cout<<it <<" ";
    }

}

int main(){

    int n;
    cout<<"enter the even value of n";
    //as there will be same no of positives and negetives
    cin>>n;

    vector<int> arr;

    cout<<"values";

    for(int i=0 ; i< n ; i++){

        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    varityTwo(arr,n);

    return 0;
}