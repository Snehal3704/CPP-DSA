
#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}


void pascalTriangle(int n) {
    for(int r=1 ; r<= n ; r++){
        for(int c =1 ; c <= r ; c++){
            cout<< nCr(r-1 , c-1)<<" ";
        }
        cout<<endl;
    }
}

vector<int> pascalTriangle_byRow(int n) {
    long long ans = 1;
    vector<int> temp;
    temp.push_back(1); // adding 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        temp.push_back(ans);
    }

    return temp;
    
}

void print_Pastri(int n){
vector<vector<int>> ans;
    for(int row =1 ; row <= n ; row++){
        ans.push_back(pascalTriangle_byRow(row));
    }

    for(int i=0 ; i < ans.size() ; i++){
        for(int j =0 ; j< ans[i].size() ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    cout<<"enter rows";
    int n ;
    cin>>n;
    
    print_Pastri(n);
    
    return 0;
}
