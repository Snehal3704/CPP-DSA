#include<bits/stdc++.h>

using namespace std;

int cntSetBits(int n){

    int cnt =0;

    while( n!=0){
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}


int minBitFlips(int start, int goal) {
        int ans = start ^ goal;

        return cntSetBits(ans);
    }

int main(){

    int initial = 10;
    int goal = 7;

    cout<<minBitFlips(initial,goal);
}