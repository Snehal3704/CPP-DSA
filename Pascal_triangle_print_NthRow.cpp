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

//print the givven row

//Time Complexity: O(n*r), where n is the given row number, and r is the column index which can vary from 0 to n-1.
//Reason: We are calculating the element for each column. Now, there are total n columns, and for each column, the calculation of the element takes O(r) time where r is the column index.
void printRowBrute(int row ){
    //Nth row -> n no of elemnts
    //ex 2th row = 2 elements;
    for(int c=1 ; c<= row ;c++ ){    //thats why we are taking till row
        cout<< NcR(row-1 , c -1) <<" ";
    }

    
}


//Time Complexity: O(N) where N = given row number. Here we are using only a single loop.
void printRowOptimal(int row){

    long long ans =1 ;

    cout << ans << " "; // printing 1st element
    for(int c = 1 ; c < row ; c++){

        ans = ans * (row - c);
        ans = ans /c;

        cout<< ans <<" ";
    }
}

int main(){
    

    cout<<"enter rows";
    int row;
    cin>>row;

    cout<<"enter cols";
    int col;
    cin>>col;

    printRowOptimal(row);

}