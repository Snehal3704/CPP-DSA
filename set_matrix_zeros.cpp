#include<bits/stdc++.h>

using namespace std;

void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> brute(vector<vector<int>> matrix, int rows, int cols) {
    // First pass: mark rows and cols that contain 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, rows, cols, i);
                markCol(matrix, rows, cols, j);
            }
        }
    }
    
    // Second pass: set -1 to 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
    
    return matrix;
}

vector<vector<int>> better(vector<vector<int>> matrix , int rows , int cols){

    vector<int> n(rows,0);  //// array for storing the values of the rows where the elemente is 0
    vector<int> m(cols,0);

    for(int i=0 ; i< rows ; i++){
        for(int j=0 ; j<cols ; j++){   //O(n*m)

            if(matrix[i][j] == 0){
                 // mark ith index of row wih 1:
                n[i] = 1;

                // mark jth index of col wih 1:
                m[j] = 1;
            }
        }
    }
    // Replacing with 0 in the selected rows
    for(int i = 0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){

            if(n[i] || m[j]){
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;

}

vector<vector<int>> optimal(vector<vector<int>> matrix , int rows , int cols){
    // We can't take the first row and coloumn in our account 
    // then the (0,0)th element will appear in both flagging row and coloumn
    // that will create collison 

    // so we will take the first coloumn as it is as our flagging coloumn
    // but we will take the the flagging row as the first row except the (0,0)th element
    // but we have to keep the (0,0)th element in our account 
    // to compare it with the elements in the first coloumn later
    // so we flag the first element as an intiger value
    // which is "col0 = matrix[0][0]"

    int col0=1;
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            if(matrix[i][j] ==0 ){

                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
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
