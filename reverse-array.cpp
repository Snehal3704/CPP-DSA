// #include<bits/stdc++.h>

// using namespace std;

// int main(){

//     int size,i,j;
//     vector<int> arr;


//     cout<<"size of array";
//         cin>> size;

//     i = 0;
//     j=size-1;

//     cout<<"enter numbers";

//     while(size--){
//         int temp;
//         cin>>temp;
//         arr.push_back(temp);
//     }

//     while(i<j){
//         swap(arr[i],arr[j]);
//         i++;
//         j--;
//     }

//     for(auto it : arr){
//         cout<< it <<" ";
//     }

//     return 0;
// }

//Using recursion

#include<bits/stdc++.h>

using namespace std;

void reverse_array(vector<int> &arr,int i,int j){
    if(i>=j) return;

    swap(arr[i],arr[j]);
    reverse_array(arr,i+1,j-1);
}

int main(){

    int size,i,j;
    vector<int> arr;


    cout<<"size of array";
        cin>> size;

    

    cout<<"enter numbers";

    for(int i =0 ;i < size ; i++){
        int temp;
        cin>> temp;
        arr.push_back(temp);
    }

    reverse_array(arr,0,size-1);

    for(int i=0 ; i< size ; i++){
        cout<< arr[i] <<" ";
    }
    // for(auto it : arr){
    //     cout<< it <<" ";
    // }

    return 0;
}