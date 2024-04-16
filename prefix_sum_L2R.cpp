#include<bits/stdc++.h>
//indexing 0
using namespace std;

int main()
{
    int size=0;
    int q=0;
    vector<int> vt;
    unordered_map<int,int> mpp;
    

    cout<<"array size";
    cin>>size;

    cout<<"values";

    for(int i=0 ; i< size ; i++){
        int temp;
        cin>>temp;
        vt.push_back(temp);

        mpp[0]=vt[0];
        mpp[i+1] = mpp[i] + vt[i];
    }
    
    // for(int i=1; i<= size ; i++){
    //     mpp[i] = mpp[i-1] + vt[i];        // for 1 indexing
    // }
    
    // cout<<"quaries";
    // cin>>q;

    
        cout<<"l and r values";
        int l,r;
        cin>>l>>r;
        if(l==0) cout<< mpp[r];
        cout<<(mpp[r] - mpp[l-1] ) <<endl;
    
    return 0;
}
