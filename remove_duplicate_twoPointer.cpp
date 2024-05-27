#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    vector<int> arr;
    int ind =0;
    int j =1;

    cout<<"size";
    cin>> n;

    cout<<"values in sorted order";

    for(int i= 0; i< n ; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for(int i= 0 ; i <n -1  ; i++){

        if(arr[ind] == arr[j]){
            j++;
        }
        else{
            ind++;
            arr[ind] = arr[j];

            /*
            or
            arr[ind +1] = arr[j];
            ind++;
            */
            
        }
    }
    
    
    for(int i=0 ; i<= ind ; i++){
        cout<<arr[i] << " ";
    }

    
    


}