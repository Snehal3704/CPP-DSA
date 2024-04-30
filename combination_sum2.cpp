#include <bits/stdc++.h>

using namespace std;

void getcombination(vector<int> vt,vector<vector<int>> &res, int ind, int target,int size,vector<int> &temp){


    if(target == 0){
        for(auto it: temp){
            cout<<it<<" ";
        }
        cout<<"\n";
        //res.push_back(temp);
        return;
    }
        

    for(int i = ind ; i < vt.size() ; i++){
        if(i>ind and vt[i] == vt[i-1])
        continue;
        if(target >= vt[i])        // for sorted array 
    {
        temp.push_back(vt[i]);
        getcombination(vt,res,i+1,target-vt[i],size,temp);        //pick
        temp.pop_back();
           
    }
    

    }
    
}


int main(){

    int size;
    int target;
    vector<int> vt;


    cout<<"size";
    cin>>size;

    cout<<"target";
    cin>>target;

    cout<<"values";

    for(int i=0 ; i< size ; i++)
    {
        int temp;
        cin>>temp;
        vt.push_back(temp);
    }

    vector<int> temp;
    vector<vector<int>> res;
    int ind=0;

    sort(vt.begin(),vt.end());

    getcombination(vt,res,ind,target,size,temp);

    // for(int i=0 ; i< res.size() ; i++)
    // {
    //     for(int j=0 ; j<res[i].size(); j++){
    //         cout<<res[i][j] <<" ";
    //     }
    //     cout<<"\n";
    // }

}
