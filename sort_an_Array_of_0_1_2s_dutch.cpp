#include<bits/stdc++.h>

using namespace std;

void swap(int &x, int &y){
    x = x xor y;
    y = x xor y;
    x = x xor y;
}

void DutchNationalFlagAlgo(vector<int> arr , int n){

    int low = 0 , mid =0;
    int high = n - 1;//arrays last element 



    while(mid <= high){

        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    for (auto it: arr){
        cout<< it <<" ";
    }
}

void better(vector<int> arr, int n){

    int one_cnt=0 , two_cnt =0 ; 
    int zero_cnt =0;
//this runns for O(n)
    for(int i=0 ; i< n ; i++){
        if(arr[i] == 0){
            zero_cnt++;
        }
        else if(arr[i] == 1){
            one_cnt++;
        }
        else{
            two_cnt ++;
        }
    }
//this total = O(n)
    for(int i=0 ; i< zero_cnt ; i++){
        arr[i] = 0;
    }
    for(int i=zero_cnt ; i < zero_cnt + one_cnt ; i++){
        arr[i] =1;
    }
    for(int i =zero_cnt + one_cnt; i< n; i++){
        arr[i] =2;
    }

    for(auto it : arr){
        cout << it << " ";
    }
//toal t.c = O(2n) and s.c=O(1)
}

int main() {
    // Fixed the prompt message
    cout << "Enter size of array: ";
    int n;
    cin >> n;

    
    vector<int> arr(n);

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    better(arr,n);
    
    return 0;
}
