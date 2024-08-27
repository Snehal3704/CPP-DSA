#include<bits/stdc++.h> 
using namespace std;

// Time Complexity = O(N^2)
// Space Complexity = O(1)

void brute(vector<int> arr, int n){
    int cnt = 0; 
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > (2*arr[j])){
                cnt++; 
            }
        }
    }

    cout<< cnt  << endl;
}

// Time Complexity = 2N*log(N)
// Space Complexity = O(N)

void merge(vector<int> &arr, int low, int mid, int high){

    vector<int> temp; 
    int left = low; 
    int right = mid+1; 

    int cnt = 0; 

    while(left<=mid and right<=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++; 
        }
        else{
            temp.push_back(arr[right]);
            right++; 
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]); 
        left++; 
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++; 
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low]; 
    }
}

// Number of pairs that each left elements can make 
int counting(vector<int> arr, int low, int mid, int high){
    int cnt = 0;
    int right = mid+1; 

    for(int i=low; i<=mid; i++){
        while(right<=high and arr[i] > 2*arr[right]){
            right++;  // looping umtil there is such element that the pair can not formed
        }
        cnt = cnt + right - mid - 1;  // number of elements in right array that can make the pairs with each left element
    }
    return cnt; 
}
int mergesort(vector<int> &arr,  int low, int high){
    int cnt = 0; 

    if(low >= high) return cnt; 

    int mid = (high+low)/2;

    cnt  = cnt + mergesort(arr, low, mid);  // it will go to some depth and its rplaced by 'cnt' through counting function in follow up depth in a tree
    cnt = cnt + mergesort(arr, mid+1, high); // same will go for this 

    cnt = cnt + counting(arr, low, mid, high);  // counts before merging (but the left and the right array are already sorted through tree in depth)

    merge(arr, low, mid, high);  // merges

    return cnt; 
}

int main(){ 
    int n;
    cout<<"enter the size of the array " ;
    cin >> n; 
    vector<int> arr; 

    cout<<"enter the elements of the array "; 
    for(int i=0; i<n; i++){
        int a; 
        cin >> a; 
        arr.push_back(a); 
    }

    brute(arr, n);
    int count = mergesort(arr, 0, n-1); 
    cout<<count<<endl;
}