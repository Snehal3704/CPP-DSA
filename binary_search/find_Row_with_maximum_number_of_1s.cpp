#include<bits/stdc++.h>

using namespace std;

int brute(vector<vector<int>> arr ,int n ,int m){

    int maxCnt= 0;

    int index= -1;


    for(int i=0 ; i< n ; i++){

        int curr_cnt = 0;

        for(int j =0 ; j < m ; j++){

            curr_cnt+=arr[i][j];
        }
        
        if (curr_cnt > maxCnt){
            maxCnt = curr_cnt;
            index =i ;
        }

    }

    return index;

}

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}


int optimal(vector<vector<int>> arr, int n, int m){
    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(arr[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}


int main(){

    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
        brute(matrix, n, m) << '\n';


    return 0;

}