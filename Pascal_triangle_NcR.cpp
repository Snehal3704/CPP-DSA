#include <bits/stdc++.h>

using namespace std;

// for finding nth row and rth col element value
int NcR(int row , int col){
     
    long long res = 1;

    for(int i = 0 ; i < col ; i++){

        res = res * (row-i);

        res = res/ (i+1);

    }

     return res;

}

int main(){
    

    cout<<"enter rows";
    int row;
    cin>>row;

    cout<<"enter cols";
    int col;
    cin>>col;


    //cout<< "value of %d row of %d column" << row ,col;
    int ans = NcR(row - 1,col - 1);

    cout<<ans;



}