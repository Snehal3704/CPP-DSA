#include<bits/stdc++.h>

using namespace std;

void get_allsubsequences(vector<int> arr,int ind , vector<int> &temp , int size){
    

    for(int i =ind ; i<= size ; i++){
    if(i>ind and arr[i] == arr[i-1])  continue;

    if(i == size){
        cout<<"[";

        for(auto it : temp){
            cout<< it <<" ";
        }
        cout<<"]";
        
        cout<<endl;
        
    }
    
    temp.push_back(arr[i]);
    get_allsubsequences(arr,i+1,temp,size);
    temp.pop_back();
    //get_allsubsequences(arr,i+1,temp,size);

    }
        
}
int main(){

    int size;
    int ind;
    vector<int> arr , temp;


    cout<<"size";
    cin>>size;

    cout<<"values";

    for(int i=0 ; i< size ; i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }


    get_allsubsequences(arr,0,temp,size);
}