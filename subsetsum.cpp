#include<bits/stdc++.h>

using namespace std;

void getsubsetsum(vector<int> &arr,vector<int> &temp,int ind,int size, int sum){
    if(ind == size){
        temp.push_back(sum);
        return;
    }
    
    getsubsetsum(arr,temp,ind+1,size,sum+arr[ind]);     //pick
    getsubsetsum(arr,temp,ind+1,size,sum);              //nonpick
}

int main(){

    int size;
    int target;
    vector<int> arr;


    cout<<"size";
    cin>>size;

    // cout<<"target";
    // cin>>target;

    cout<<"values";

    for(int i=0 ; i< size ; i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    vector<int> temp;
    int sum=0;
    int ind=0;

    getsubsetsum(arr,temp,ind,size,sum);

    sort(temp.begin(),temp.end());

    for(int i=0 ; i< temp.size() ; i++)
    {
        cout<<temp[i] <<" ";
    }

}