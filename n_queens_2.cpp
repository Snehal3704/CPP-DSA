#include<bits/stdc++.h>
using namespace std;
void solve(int col, int n, vector<string> board, vector<int> leftRow, vector<int> lowerDiagonal, vector<int> upperDiagonal){

    if(col == n){
        for(auto it : board){
            cout<<it<<endl;
        }
        cout<<endl;
        return;
    }
    
    for(int row=0; row<n; row++){
        if(leftRow[row] == 0 and lowerDiagonal[row + col] == 0 and upperDiagonal[col + n-1 - row] == 0){
           
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[col + n-1 - row] = 1;
            solve(col+1, n, board, leftRow, lowerDiagonal, upperDiagonal);
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[col + n-1 - row] = 0;
            board[row][col] = '.';
        }
    }
}

int main(){
    int n; 
    cout<<"enter the size ";
    cin >> n; 
    string str(n, '.');
    vector<string> board(n);

    for(int i=0; i<n; i++){
        board[i] = str;
    }

    vector<int> leftRow(n, 0);
    vector<int> lowerDiagonal(2*n - 1, 0);
    vector<int> upperDiagonal(2*n - 1, 0);
    
    cout<<"before the board was"<<endl;
    for(auto it : board){
        cout<<it<<endl;
    }
    cout<<"after the board is "<<endl;

    solve(0, n, board, leftRow, lowerDiagonal, upperDiagonal);
}