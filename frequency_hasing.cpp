#include<bits/stdc++.h>

using namespace std;

int main()
{
    cout<<"array size";
    int size;
    cin>>size;
    int arr[size];
    unordered_map<int,int> mpp;  

    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
        mpp[arr[i]]++;            //precompute
    }

    //iterate in the map
    for(auto it : mpp){
        cout<< it.first <<"->" << it.second<<endl;
    }


    cout<<"how many number or query are you giving?";
    int n;
    cin>>n;
    while(n--){                     //fetching
        cout<<"queries:";
        int number;
        cin >> number;
        cout<<mpp[number] << endl;
    }
    
    return 0;
}