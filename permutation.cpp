#include<bits/stdc++.h>

using namespace std;

void getpermutations(vector<vector<int>> &res , vector<int> &temp , vector<int> arr , int size,int visited []){

    if(temp.size() == size){
        res.push_back(temp);
        return;
    }

    for(int i = 0 ; i < size ; i++){
        if(! visited[i]){
            
            temp.push_back(arr[i]);
            visited[i]  = 1;
            getpermutations(res,temp,arr,size,visited);
            visited[i]  = 0;
            temp.pop_back();

        }
    }

}

int main(){
    
    int size;
    cout<< "size";
    cin>>size;

    cout<<"values";

    vector<int> arr;
    int visited[size] = {0};

    for(int i=0 ; i<size; i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);

    }
    vector<vector<int>> res;
    vector<int> temp;
    int ind = 0;

    getpermutations(res,temp,arr,size,visited);
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
