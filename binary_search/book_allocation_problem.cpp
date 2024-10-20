#include<bits/stdc++.h>

using namespace std;

int check_book_allocation(vector<int> arr,int book, int m){

    int capacity =0;
    int cnt=1;

    for(int i=0 ; i< arr.size() ; i++){
        capacity +=arr[i]; 

        if(capacity > book){
            cnt++;
            capacity = arr[i];
        }
    }

    if(cnt > m) return false;
    else    return true;


}

int findPages(vector<int> arr,int  n,int  m){

    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    while(low <= high){

        int mid = (low + high ) >>  1;

        int possible = check_book_allocation(arr,mid,m);

        if(possible){
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
    vector<int> arr = {12, 34, 67, 90};
    int n = 4;
    int m = 2;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}