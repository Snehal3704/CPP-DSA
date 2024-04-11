#include <bits/stdc++.h>
using namespace std;

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

    int sum = 0,len = 0,Max=0;
    unordered_map<int,int> mpp;

    for( int i=0 ; i< size -1 ; i++)
    {
       sum  += vt[i];

        if(sum == target)
        {
            len = i+1;
            Max=max(Max,len);
        }
        int rem = sum - target;
        if( mpp.find(rem) != mpp.end())
        {
            len = i - mpp[rem];
            Max=max(Max,len);
        }


        if(mpp.find(sum) == mpp.end())
        mpp[sum] = i;
    }
    cout<< Max;
    return 0;
}