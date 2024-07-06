#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cout<<"enter n";
    cin>>n;

    vector<int>arr;
    int ans;

    // {1, 0, 1, 1, 0, 1} 

    cout<<"enter the n elements";
    for(int i=0; i<n ; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    
    int maxi=0;
    int  temp=0;
    for(int i=0 ; i< n ; i++){

        if(arr[i] ==0){
            temp=0;
        }
        else{
            temp++;

            if(temp>maxi){
                maxi=temp;
            }
        }

        // or

        // if(arr[i] ==1){
        //     temp++;
        // maxi = max(maxi,temp);
        // }
        // else{
        //     temp=0;
        // }

        
        
    }

    cout<<maxi;

}