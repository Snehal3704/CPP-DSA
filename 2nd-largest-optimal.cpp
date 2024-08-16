#include<bits/stdc++.h>

using namespace std;
int main(){
int n;
    vector<int> arr;

    cout<<"size";
    cin>> n;

    cout<<"values";

    //ex =1 2 4 7 7 5

    for(int i= 0; i< n ; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int largest =INT_MIN;
    int sec_largest = INT_MIN;
    for(int i =0 ; i< n ; i++){
        if(arr[i] > largest){
            sec_largest= largest;
            largest = arr[i];
        }
        else if (arr[i] < largest and arr[i] > sec_largest){
            
            sec_largest = arr[i];
        }
    }

    cout<<largest;
    cout<<endl;
    cout<<sec_largest;

    

}
