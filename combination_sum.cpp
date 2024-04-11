#include <bits/stdc++.h>
using namespace std;

void getcombination(vector<int> vt , int target , int size, vector<vector<int>> &res ,vector<int> temp , int pt){
    if(pt == size){
        if(target == 0){
            res.push_back(temp);
        }
        return;
    }

    if(target >= vt[pt])        // for sorted array 
    {
        temp.push_back(vt[pt]);
        getcombination(vt,target - vt[pt],size,res,temp,pt);
        temp.pop_back();
        getcombination(vt, target, size, res, temp, pt+1);
    }
    else{
       getcombination(vt, target, size, res, temp, pt+1); 
    }

    
}

int main(){
    int target;
    cout << "target ";
    cin>> target;

    int size;
    cout<< "size";
    cin>>size;

    cout<<"values";

    vector<int> vt;

    for(int i=0 ; i<size; i++)
    {
        int a;
        cin>>a;
        vt.push_back(a);

    }
    vector<vector<int>> res;
    vector<int> temp;
    int pt = 0;

   getcombination(vt,target,size,res,temp,pt);
    for(int i=0 ; i< res.size() ; i++)
    {
        for(int j=0 ; j< res[i].size() ; j++)
        {
            cout<< res[i][j] << " ";
        }
        cout<< endl;
    }


    return 0;

}