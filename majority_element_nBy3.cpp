#include<bits/stdc++.h>

using namespace std;

vector<int> better(vector<int> arr ,int n){
    unordered_map<int,int> mpp;
    vector<int> res;
    int maj_ele= (int) n/3 + 1;

    for(int i =0 ; i< n ; i++){
        mpp[arr[i]]++;
        
        if(mpp[arr[i]] > maj_ele){
            res.push_back(arr[i]);
        }
    }

    return res;
}

vector<int> optimal(vector<int> v ,int n) {
    
    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
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

    // int ans = Moores_Voting_Algorithm(arr, n);
    

    vector<int> ans = optimal(arr, n);
    for(auto it : ans){
        cout<<it <<" ";
    }

    return 0;
}
