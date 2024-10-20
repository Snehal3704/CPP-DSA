#include<bits/stdc++.h>

using namespace std;

bool checkAnd_countPartitions(vector<int> arr, int k , int curr_subarray_sum){
    int sum = 0 , cnt =1;

    for(int i= 0 ; i< arr.size() ; i++){
        sum += arr[i];

        if(sum > curr_subarray_sum){
            cnt++;
            sum = arr[i];
        }
    }

    if(cnt > k) return false;
    else    return true;

}

int optimal(vector<int> arr, int k){

    
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    while(low <= high){

        int mid = (low + high) >> 1;

        if(checkAnd_countPartitions(arr,k,mid)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }


    }
    return low;

}

int main()
{
    vector<int> a = {7,2,5,10,8};
    int k = 2;
    int ans = optimal(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}