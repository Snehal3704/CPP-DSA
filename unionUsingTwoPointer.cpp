#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cout<<"size of 1st array";
    cin>>n;

    vector<int> arr1;
    vector<int> arr2;
    

    cout<<"values of 1st array";

    for(int i=0; i<n ; i++){
        int temp;
        cin>>temp;
        arr1.push_back(temp);
    }

    cout<<"size of 2nd array";
    int m;
    cin>>m;

    cout<<"values of 2nd array";

    for(int i=0; i<m ; i++){
        int temp;
        cin>>temp;
        arr2.push_back(temp);
    }

    int i,j=0;
    vector<int> unionarr;
    //     arr1[ i ] == arr2[ j ] 
    // Here we found a common element, so insert only one element in the union. Let’s insert arr[i] in union and increment i.

    // NOTE: There may be cases like the element to be inserted is already present in the union, in that case, we are inserting duplicates which is not desired. So while inserting always check whether the last element in the union vector is equal or not to the element to be inserted. If equal we are trying to insert duplicates, so don’t insert the element, else insert the element in the union. This makes sure that we are not inserting any duplicates in the union because we are inserting elements in sorted order.

    // arr1[ i ]  < arr2[ j ]
    // arr1[ i ] < arr2[ j ] so we need to insert arr1[ i ] in union.IF last element in  union vector is not equal to arr1[ i ],then insert in union else don’t insert. After checking Increment i.
    
    // arr1[ i ] > arr2[ j ]
    // arr1[ i ] > arr2[ j ] so we need to insert arr2[ j ] in union. IF the last element in the union vector is not equal to arr2[ j ], then insert in the union, else don’t insert. After checking Increment j. After traversing if any elements are left in arr1 or arr2 check for condition and insert in the union.
    
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) // Case 1 and 2
        {
        if (unionarr.size() == 0 || unionarr.back() != arr1[i])
            unionarr.push_back(arr1[i]);
        i++;
        } else // case 3
        {
        if (unionarr.size() == 0 || unionarr.back() != arr2[j])
            unionarr.push_back(arr2[j]);
        j++;
        }
    }
    while (i < n) // IF any element left in arr1
    {
        if (unionarr.back() != arr1[i])
        unionarr.push_back(arr1[i]);
        i++;
    }
    while (j < m) // If any elements left in arr2
    {
        if (unionarr.back() != arr2[j])
        unionarr.push_back(arr2[j]);
        j++;
    }

    for(auto it: unionarr){
        cout<< it <<" ";
    }

}