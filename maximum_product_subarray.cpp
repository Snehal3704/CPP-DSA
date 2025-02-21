#include<bits/stdc++.h> 
using namespace std; 

// KADANE's Algorithm 
// Time Complexity = O(N)
// Space Complexity = O(1) 

//lowest negetive can be higest positive if encountring with neg no
int optimal1(vector<int> arr){
    int n = arr.size();
        if (n == 0) return 0;

        int max_product = INT_MIN;
        int min_product = INT_MAX;
        int result = arr[0];

        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                swap(max_product, min_product);
            }

            max_product = max(arr[i], max_product * arr[i]);
            min_product = min(arr[i], min_product * arr[i]);
            cout<< max_product <<" " <<min_product <<" "<<endl;

            result = max(result, max_product);
            cout<<result<<" ";
        }
        cout<<endl;

        return result;
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
    vector<int> arr = {-1 , -3 , -2 , 1};
    cout<<endl;
    cout<< optimal1(arr); 
}
