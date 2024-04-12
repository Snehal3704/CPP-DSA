#include<iostream>

using namespace std;

int main()
{
    cout<<"enter the string";
    string s;
    cin>>s;


    int hash[26] = {0};         //precompute
    for(int i=0; i<s.size(); i++)
    {
        hash[s[i] - 'a']++;
    } 

    cout<<"how many number or query are you giving?";
    int n;
    cin>>n;
    while(n--){                     //fetching
        cout<<"queries:";
        char charecter;
        cin >>charecter;
        cout<<hash[charecter - 'a'] << endl;
    }
    
    return 0;
}