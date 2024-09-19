#include<bits/stdc++.h>

using namespace std;

int required_time(vector<int> arr, int current_rate){
    int total_h=0;

    for(int i= 0 ; i< arr.size();i++){
        total_h += ceil((double)(arr[i]) / (double)(current_rate));

        //or
        //total_h += (arr[i] + current_rate - 1) / current_rate;

        
        //For any integer division a / b:
        //Using (a + b - 1) / b ensures you get the ceiling value.
    }
    return total_h;
}

int brute(vector<int> arr , int h){

    int n= arr.size();
    //max element gives tthe iterator to the max element so we need pointer
    int  maxi = *max_element(arr.begin(),arr.end());

    for(int i=1 ; i<= maxi ; i++){
        int current_time= required_time(arr,i);

        if (current_time <= h) {
            return i;
        }
        
    }

    //dummy statement

    return maxi;

     
    
}

int optimal(vector<int> arr, int h){

    int low= 1 , high = *max_element(arr.begin(),arr.end());

    int min_ele = INT_MAX;

    while(low <= high){

        int mid = (high - low ) / 2 + low;

        int current_time = required_time(arr,mid);

        if(current_time > h){
            low = mid + 1;
        }
        else if(current_time <= h){
            min_ele = min(min_ele,current_time);
            high = mid -1 ;
        }

        return min_ele;

    }
}
int main(){

    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = optimal(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}