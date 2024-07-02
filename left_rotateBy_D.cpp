#include<bits/stdc++.h>

using namespace std;

void bruteforce(vector<int> arr, int n , int k ){
    int temp[k];
    for(int i=0 ; i<k ; i++){
        temp[i] = arr[i];
    }

    //shifting
    int ind =0;
    for(int i=k ; i<n ; i++){
        arr[ind] = arr[i];
        ind++;
    }

    ind=0;
    for(int i=n-k ; i< n ; i++){
        arr[i] = temp[ind];
        ind++;
    }

    for(auto it : arr){
        cout<<it<<" ";
    }

}

void reverse(vector<int> arr, int start, int end){
    while(start <=end){
        int temp =arr[end];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;

    }
}

void optimal (vector<int> arr, int n, int k){
    //// Reverse first k elements
    reverse(arr,0,k -1);
    // Reverse last n-k elements
    reverse(arr,k, n-1);
    // Reverse whole array
    reverse(arr,0,n-1);

}

int main(){
    int n;
    cout<<"size";
    cin>>n;

    vector<int> arr;

    cout<<"values";

    for(int i=0; i<n ; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    int k;
    cout<<"enter k";
    cin>>k;

    k = k % n;


    bruteforce(arr,n,k);


}
