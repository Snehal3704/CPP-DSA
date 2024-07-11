#include<bits/stdc++.h>

using namespace std;

// Time Complexity = O(2n) 
// every time the inner loop does not run for n times rather it can run for n times in total. 
// So, the time complexity will be O(2*N) instead of O(N^2).
// Space Complexity = O(1)

//if the array contains only positves and zeros
int optimal(vector<int> &arr , int n, long long k){
    long long sum = arr[0];
    int left =0 , right =0;
    int maxlen =0;

    while(right < n){

        while(left <= right and sum > k){

            sum-=arr[left];
            left++;
        }

        if(sum ==k ){
            maxlen = max(maxlen , right - left +1); 
        }

        right++;
        if(right < n){

        sum+= arr[right];
        }


    }

    return maxlen;

}


// Time Complexity = nlog(n)(using map)
// Time Complexity = O(n) (using unordered_map) // but in worst case unordered_map will take O(n^2)
// Space Complexity = O(N) (as we are using map)

int better(vector<int> &arr,int n, long long k){

//can work for positive and negetive in the arrays

    map<long long,int> prefixsum;
    long long sum=0;
    int maxlen =0;

for(int i=0 ; i< n ; i++){
   //calculate the prefix sum till index i:
    sum+=arr[i];
    if(sum == k){
        maxlen = max(maxlen,i+1);
    }
    // calculate the sum of remaining part i.e. x-k:
    long long rem =sum - k;

     //Calculate the length and update maxLen:
    if(prefixsum.find(rem) !=prefixsum.end()){
        int len = i - prefixsum[rem];
            maxlen = max(maxlen, len);
    }
    //Finally, update the map checking the conditions:
        if (prefixsum.find(sum) == prefixsum.end()) {
            prefixsum[sum] = i;
        }
    

}

return maxlen;
}

// Time Complexity = O(n^2)
// Space Complexity = O(1)
int bruteforce(vector<int> &arr, int n , long long k){

    int length =0;
    for(int i=0 ; i< n ; i++){
        for(int j=i ; j<n ; j++){
            int sum=0;

            sum+=arr[j];
            if(sum == k)    length = max(length , (j-i)+1);
            // for(int l=i ; k<j ; k++){
            //     sum+=arr[l];

            //     if(sum == k)    length = max(length , (j-i)+1); //(j-i)+1 = current subarray size
            // }
        }
    }
    return length;
}


int main(){

    int n;
    cout<<"enter n";
    cin>>n;

    vector<int>arr;
    int ans;

    
    //1,2,3,1,1,1,1,4,2,3
    cout<<"enter the n elements";
    for(int i=0; i<n ; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<"enter k";
    long long k;
    cin>>k;
    
    ans = optimal(arr,n,k);
    cout<<ans;
    return 0;
}
