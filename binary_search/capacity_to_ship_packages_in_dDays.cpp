#include<bits/stdc++.h>

using namespace std;

int daysRequired(vector<int>arr,int cap){

    int days = 1; //First day.
    int load = 0;
    int n = arr.size(); //size of array.
    for (int i = 0; i < n; i++) {
        if (load + arr[i] > cap) {
            days += 1; //move to next day
            load = arr[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            load += arr[i];
        }
    }
    return days;
}

int optimal(vector<int>arr,int d){

    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    while(low <= high){
        
        int mid = (low + high) >> 1;

        int numberOfDays = daysRequired(arr, mid);

        if (numberOfDays <= d) {
            //eliminate right half
            high = mid - 1;
        }
        else {
            //eliminate left half
            low = mid + 1;
        }
    }
    return low;
    }




int main()
{
    vector<int> arr = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = optimal(arr, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}