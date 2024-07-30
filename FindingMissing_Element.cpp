#include<bits/stdc++.h>

using namespace std;

int brute(vector<int> &arr , int n){

    // Outer loop that runs from 1 to N:
    for (int i = 1; i <= n; i++) {

        // flag variable to check
        //if an element exists
        int flag = 0;

        //Search the element using linear search:
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] == i) {

                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing
        //i.e flag == 0:

        if (flag == 0) return i;
    }
}

int better(vector<int> &arr , int n){

    int hasharr[n+1] = {0};
    
    for(int i = 0 ; i< n-1 ; i++){
        hasharr[arr[i]]++;
    }
    for(int i = 1 ; i<=n; i++){
        if(hasharr[i] ==0){
            return i;
        }
    }

    
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
    
    int res = better(arr,n);
    cout<< res ;

    return 0;


}
