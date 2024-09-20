#include<iostream>

using namespace std;

int main()
{
    cout<<"array size";
    int size;
    cin>>size;
    int arr[size];

    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    int hash[13] = {0};         //precompute
    for(int i=0; i<size ; i++)
    {
        hash[arr[i]] +=1;
    } 

    
    cout<<"how many number or query are you giving?";
    int n;
    cin>>n;
    while(n--){                     //fetching
        cout<<"queries:";
        int number;
        cin >> number;
        cout<<hash[number] << endl;
    }
    
    return 0;
}
