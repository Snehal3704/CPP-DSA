#include<bits/stdc++.h>

using namespace std;

int brute(vector<int> arr){
    unordered_map<int,int> mpp;

    int n = arr.size();

    for(int i=0 ; i< n ; i++){
        mpp[arr[i]]++;
    }
    for(int i= 0 ; i< n ; i++){
        if(mpp[arr[i]] == 1){
            return arr[i];
        }
    }
    /*
    for (auto it : mpp) {
        if (it.second == 1) {
            return it.first;
        }
    }
    */

   // If no element with frequency 1 is
    // found, return -1 as input invalid
    return -1;
}

int better(vector<int> arr) {
    int ans = 0;

    // Iterate through each bit position
    for (int bitIndex = 0; bitIndex < 32; bitIndex++) {
        int sum = 0;

        // Count the number of elements with the current bit set
        for (int i = 0; i < arr.size(); i++) {
            if ((arr[i] & (1 << bitIndex)) != 0) { // Correct precedence
                sum++;
            }
        }

        // Check if the bit contributes to the unique number
        if (sum % 3 != 0) {
            ans |= (1 << bitIndex); // Set the bit in the result
        }
    }

    return ans;
}

int bySorting(vector<int> arr){
    sort(arr.begin(),arr.end());

    for(int i = 1; i < arr.size() ; i = i+3){
        if( arr[i] != arr[i -1]){
            return arr[i -1];
        }
    }

    return arr[arr.size() -1 ];
}

int optimal(vector<int> arr){
    int ones = 0 , twos =0;

    //twos is geeting random values in middle as it is not getting same values valuea causing diff values to store

    for(int i =0 ; i < arr.size() ; i++){
        ones = ( ones ^ arr[i] ) & ~twos;
        cout<< ones <<endl;

        twos = ( twos ^ arr[i] ) & ~ones;

        cout<< twos << endl;

    }
    cout<< endl;

    return ones;
}


int main(){
    vector<int> arr ={5,3,4,5,4,4,5};
    cout<< optimal(arr);
}

