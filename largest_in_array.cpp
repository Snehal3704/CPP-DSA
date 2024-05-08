
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> arr;

    cout<<"size";
    cin>> n;

    cout<<"values";

    for(int i= 1; i< n ; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int largest = arr[0];

    for(int i=0 ; i< n ; i++){
        if(arr[i] > largest)
        largest = arr[i];
    }

    cout<< largest; // t.c == O(N)


}
