#include<bits/stdc++.h> 
using namespace std; 

// KADANE's Algorithm 
// Time Complexity = O(N)
// Space Complexity = O(1) 

void optimal1(vector<int> arr, int n){
    int right = 0;  
    int prod = 1; 
    int maxi = 1; 

    while(right < n){
        prod = prod*arr[right];
        if(prod == 0){
            prod = 1; 
        }
        maxi = max(maxi, prod);
        right++; 
    }
    cout<< maxi<<endl;
}


// Time Complexity = O(N)
// Space Complexity = O(1)

// 1. if there is no negetive number , product of all elements is maximum
// 2. if there is even negetive number , product of all elements is maximum
// 3. if there is odd negetive number , either product of all elements before or after odd numbers of negetive numbers is maximum
// 4. if there is 0 then after reaching zero change the product to 1 and make new products after 0, find maximum this way 

void optimal2(vector<int> arr, int n){
    int maxi = INT_MIN; 

    int presum = 0; 
    int sufsum = 0 ; 
    for(int i=0; i<n; i++){
        if(presum == 0){
            presum = 1;
        }
        if(sufsum == 0){
            sufsum = 1;
        }

        presum = presum*arr[i]; 
        sufsum = sufsum*arr[n-1-i]; 

        maxi = max(maxi, max(presum, sufsum)); 
    }

    cout << maxi << endl;
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

    optimal1(arr, n)  ;
    optimal2(arr, n)  ;
}