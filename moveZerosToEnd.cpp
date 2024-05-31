#include<bits/stdc++.h>

using namespace std;

void optimal(vector<int> arr , int n){
    int j=-1;
    //after iterating if j=-1 then there is no zero
    for(int i=0 ; i< n ; i++){
        if( arr[i] == 0){
            j=i;
            break;
        }
    }

    if(j == -1) cout<<"there is no zero in the array" ;

    for(int i= j+1 ; i< n;i++){
        if(arr[i] !=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }

    for(auto it : arr){
        cout<< it << " ";
    }

   
}



int main(){
    int n;
    cout<<"size";
    cin>>n;

    vector<int> arr;
    vector<int> arr2;
    vector<int> main;
    cout<<"values";

    for(int i=0; i<n ; i++){
        int temp;
        cin>>temp;
        if(temp == 0){
            arr2.push_back(temp);
        }
        else{

        arr.push_back(temp);
        }
        main.push_back(temp);
    }
    // for(int i=0 ; i< arr2.size() ; i++){
    //     arr.push_back(arr2[i]);
    // }

    // for(auto it : arr){
    //     cout<< it << " ";
    // }

    optimal(main,n);
   



}