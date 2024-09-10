#include<bits/stdc++.h>

using namespace std;

// Time Complexity = N^4 (ignoring sorting)
// Space Complexity =  O(2 * no. of the quadruplets) 
// as we are using a set data structure and a list to store the quads.
vector<vector<int>> brute(vector<int> arr , int n , int target){
    set<vector<int>> st;

    
    for(int i =0 ; i< n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            for(int k = j +1 ; k < n ; k++){
                for(int l = k+1 ; l < n ; l++){
                    long long sum = arr [i] + arr [ j];

                    sum = sum + arr[k];
                    sum = sum + arr[l];

                    if(sum == target){
                        vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin() ,temp .end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());

    return ans;

}

// Time Complexity = O(N^3*log(M)) M = no. of elements in the set.
// Space complexity = O(2 * no. of the quadruplets)+O(N)


vector<vector<int>> better(vector<int> arr, int n , int target){

    set<vector<int>> st;

    for(int i = 0 ; i < n ; i++){
        for(int j = i +1 ; j < n ; j++){
            set<long long> hashst ;
            for(int k = j +1 ; k < n ; k++){
                long long sum = arr[ i] + arr[j];
                sum = sum + arr[k];
                long long need = target - sum;
                if(hashst.find(target) != hashst.end()){
                    vector<int> temp = {arr[i] , arr[j],arr[k],(int)(need)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // put the kth element into the hashset:
                hashst.insert(arr[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;

}

// Optimal

// Time Complexity = N^3 + Nlog(N)
// Space Complexity = O(number of unique quadriplets)
// ignoring vector<vector<int>> ans 
vector<vector<int>> optimal(vector<int> arr , int n, int target){
    vector<vector<int>> ans;

    sort(arr.begin(),arr.end());

    for(int i=0 ; i< n ; i++){
        // avoid the duplicates while moving i:
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        for(int j =i+1 ; j< n ; j++ ){

            // avoid the duplicates while moving j:
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;

            //2 pointer
            int k = j+1 ; 
            int l = n-1 ;

            while (k < l) {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if (sum == target) {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && arr[k] == arr[k - 1]) k++;
                    while (k < l && arr[l] == arr[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }

        }
    }
    return ans;
}

int main(){

    cout<<"enter size";
    int n;
    cin >> n;

    cout<<"enter the values";

    vector<int> arr;
    for(int i=0 ; i< n ; i++){

        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    cout << "Enter target: ";
    int target;
    cin >> target;

    vector<vector<int>> ans = optimal (arr, n ,target);

    for(int i =0 ; i< ans.size() ; i++){

        cout << "[";
        for(int j =0 ; j< ans[i].size() ; j++){
            cout<<ans[i][j] <<" ";
        }
        cout << "] ";
    }
    cout << "\n";



}
