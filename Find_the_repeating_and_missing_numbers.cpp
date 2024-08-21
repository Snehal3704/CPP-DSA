#include<bits/stdc++.h>

using namespace std;

vector<int> better(vector<int> arr){
    int n = arr.size(); // size of the array
    int hash[n + 1] = {0}; // hash array

    //update the hash array:
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    //Find the repeating and missing number:
    int repeating = -1, missing = -1;

    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) repeating = i;
        else if (hash[i] == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};

}

// Time Complexity = O(N)
// Space Complexity = O(1)

void optimal(vector<int> arr, int n){
    long long sn1 = n*(n+1)/2;  // summation of N digits
    long long sn2 = n*(n+1)*(2*n+1)/6;  // Summation of square of N digits

    long long s1 = 0; 
    long long s2 = 0; 
    for(int i=0; i<n; i++){
        s1 = s1 + arr[i]; // sum of the array
        s2 = s2 + (arr[i]*arr[i]); // sum of the square of the array elements
    }

    long long x = s1 - sn1;  // x = repeating - missing
    long long y = s2 - sn2;  // y = repeating^2 - missing^2 = (repeating + missing)(repeating - missing)
    y = y/x ;   // y = repeating + missing

    long long  repeat = (x+y)/2; 
    long long  missing = (y-x)/2; 

    cout << "repeating number is "<< repeat << endl;
    cout << "missing number is "<< missing << endl;
}



int main(){
    vector<int> arr = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = better(arr);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}