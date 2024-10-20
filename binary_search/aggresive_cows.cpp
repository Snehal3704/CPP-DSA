#include<bits/stdc++.h>

using namespace std;

bool CanWePlace(vector<int>stalls,int dis,int cows){

    int curr_cow_cnt=1; // we are placing the ist cow at 0th index

    int last_Placed_cow_cordinate=stalls[0];

    for(int i = 1 ; i< stalls.size(); i++){
        if (stalls[i] - last_Placed_cow_cordinate >= dis) {
            curr_cow_cnt++; //place next cow.
            last_Placed_cow_cordinate = stalls[i]; //update the last location.
        }
        if (curr_cow_cnt >= cows) return true;//its ok to place cows by maintaing a min distance
    }
    return false;


}

int binary_search(vector<int> stalls,int cows){
    
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int low =1 , high = stalls[n-1] - stalls[0];

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (CanWePlace(stalls, mid, cows) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}

int aggressiveCows(vector<int> &stalls, int cows) {

    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    // range should be 1 - ( max element - min element ) --> this is optimized range
    //as array is sorted so last elemet is max ele and last ele is the min 
    int range = stalls[n-1] - stalls[0];
    

    for(int i= 1 ; i < range ; i++ ){
        if(CanWePlace(stalls,i,cows) == false){
            return (i-1);
        }
    }
    return range;
}

int main(){

    vector<int> stalls = {0, 3, 4, 7, 10, 9};   // cordinates
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;

}