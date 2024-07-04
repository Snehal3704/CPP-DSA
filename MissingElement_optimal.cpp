#include<bits/stdc++.h>

using namespace std;

void optimal(vector<int> &arr , int n){

    int sum = (n*(n+1))/2;

    int s2=0;

    for(int i=0 ; i< n-1 ; i++){
        s2+=arr[i];
    }

    int missing_ele =sum - s2;

    cout<<missing_ele;
}

void optimal2 (vector<int> &arr ,int n){

    int xor1 =0;
    int xor2 = 0;

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < n - 1; i++) {
        xor2 = xor2 ^ arr[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
    }
    xor1 = xor1 ^ n; //XOR up to [1...N]

    int ans= (xor1 ^ xor2); // the missing number

    cout<<ans;
}

int main(){

    int n;
    cout<<"enter n";
    cin>>n;

    vector<int>arr;
    int ans;
    cout<<"enter the n-1 elements";
    for(int i=0; i<n-1 ; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    
    optimal(arr,n);
    

    return 0;


}