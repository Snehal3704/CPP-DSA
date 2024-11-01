#include<bits/stdc++.h>

using namespace std;

int merge(vector<int> &arr, int low , int high,int mid){

    int left = low;
    int right = mid + 1;

    int cnt = 0;

    while(left <= mid and right <= high){
        if((long long)arr[left] > 2LL * arr[right]){
            cnt += mid + 1 - left;
            right++;

        }
        else{
            left++;

        }
    }

    left = low;
    right = mid + 1;
    vector<int>temp;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i= low ; i<= high ; i++){
        arr[i] = temp[i-low];
    }

    return cnt;

}

int mergesort(vector<int>&arr,int low, int high){
    if (low >= high) return 0;
    int cnt = 0;

    int mid = (low + high) >> 1;

    cnt += mergesort(arr,low , mid);
    cnt += mergesort(arr,mid+1,high);
    cnt+=merge(arr,low,high,mid);

    return cnt;
}

int team(vector<int> arr,int n){
    return mergesort(arr,0,n-1);
}


int countPairs(vector<int>&a, int n) {

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > 2 * a[j]) cnt++;
        }
    }
    return cnt;
}

int main(){
    vector<int> a = {40,25,19,12,9,6,2};
    int n = a.size();
    int cnt = countPairs(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}
