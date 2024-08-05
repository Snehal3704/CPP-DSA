#include<bits/stdc++.h>

using namespace std;

int brute(vector<int> arr, int n){

    int ans=0;
    int length =1;

    sort(arr.begin(),arr.end());

    for(int i=0 ; i< n;i++){
        if(arr[i+1] - arr[i] == 1){
            length++;
            ans = max(ans,length);
        }
        else{
            length =1;
        }
    }
    return ans;
}

int optimal(vector<int> arr,int n ){
    int longest =1;
    if(arr.size() == 0) return 0;

    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);
    }

     //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main() {
    cout << "Enter size of array: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   int ans = brute(arr,n);

   
    cout<<ans <<" ";
   


}
