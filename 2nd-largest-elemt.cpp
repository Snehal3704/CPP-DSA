#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> arr;

    cout<<"size";
    cin>> n;

    cout<<"values";

    for(int i= 0; i< n ; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
     
    // sort(arr.begin(),arr.end()); 
    // //Brute force = t.c =O(Nlogn)

    // for(int i=n-2 ; i >= 0 ; i--){
    //     if(arr[i] < arr[n-1]){
    //         scnd_largest = arr[i];
    //         break;
    //     }
    // }

    int scnd_largest=INT_MIN;
    int largest = INT_MIN;
    int smallest = INT_MAX;
    int scn_smallest = INT_MAX;

    for(int i=0 ; i< n ; i++){
        smallest = min(smallest,arr[i]);
        largest = max(largest,arr[i]);
    }

    for(int i =0 ; i< n ; i++){
        if(arr[i] > scnd_largest and arr[i] != largest)
        scnd_largest = arr[i];
        if(arr[i] < scn_smallest and arr[i] != smallest)
        scn_smallest = arr[i];
    }
    
    
        //cout << "Largest element in the array: " << largest << endl;
        cout << "Second largest element in the array: " << scnd_largest << endl;
        //cout << "Smallest element in the array: " << smallest << endl;
        cout << "Second smallest element in the array: " << scn_smallest << endl;
    
    }
