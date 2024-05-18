#include<bits/stdc++.h>

using namespace std;

bool isSafe(int n,int col,int row,vector<string> board){

int dprow = row;
int dpcol = col;

    //checking for left side(west)
    //only column is decreasing,row is constant
    while(col >= 0){
        if (board [row][col] =='Q'){
            return false;
        }
        col--;

    }
//Reinialize because the next loops will get the past col value
row = dprow;
col = dpcol;
    //chekcing for upper left side(north-east)
    //row and column both are decreasing
    while(row >= 0 and col >= 0){
        if (board [row][col] =='Q'){
            return false;
        }
        col--;
        row--;
    }

row = dprow;
col = dpcol;
    //checking for lower left sides
    //row increasing and col is decreasing
    while(row < n and col >= 0){
        if (board [row][col] =='Q'){
            return false;
        }
        col--;
        row++;
    }

    return true;

}

void solve( int col , vector<string> &board ,int n){
    if(col == n){

    for(auto it : board){
        cout<<it <<endl;
     }
     cout<<endl;
    
    return;

    }

    for(int row =0 ; row < n ; row++){

        if(isSafe(n,col,row,board)){

            board[row][col] = 'Q';
            solve(col+1 , board ,n);
            board[row][col] = '.';

        }
    }
}

int main(){

    int n;
    cout<<"board length:";
    cin>>n;

    vector<string> board(n, string(n, '.'));
    // ...
    // ...
    // ...
    //vector<vector<string >>ans;
    solve(0,board,n);

    


}