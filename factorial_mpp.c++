#include<bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<int,long long int> fact;
    long long int n;
    cout<<"enter the number";
    cin>>n;
    fact[0] = fact[1]=1;
    for(int i=2 ; i<= n ; i++)
    {
        fact[i] = fact[i-1] * i;
    }

    cout<<fact[n];
    return 0;
}