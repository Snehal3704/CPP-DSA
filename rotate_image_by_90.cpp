#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> brute(vector<vector<int>> matrix , int rows, int cols){
    int n= matrix.size();
    
    for(int i=0 ; i< n ; i++){
        for(int j=0 ; j<n ; j++){
            rotated[j][n-i-1] = matrix[i][j];
        }
    }

    return rotated;

}

vector<vector<int>> optimal(vector<vector<int>> matrix , int rows, int cols){
    int n= matrix.size();
    vector<vector<int>> rotated(n,vector < int > (n, 0));

    for(int i=0 ; i< rows ; i++){
        for(int j=0 ; j<=i ; j++){
                swap(matrix[i][j],matrix[j][i]);
            
        }
    }

    for(int i=0;i<rows;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

    return matrix;

}



int main() {
    int rows, cols;

    
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> ans = optimal(matrix, rows, cols);

    cout << "The modified matrix is:" << endl;
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
