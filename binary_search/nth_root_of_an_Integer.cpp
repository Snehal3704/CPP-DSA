#include<bits/stdc++.h>

using namespace std;

//Calculating (mid)^n

int func(int m, int n, int mid){

    // for not goint overflow
    //return 1, if == m:
    //return 0, if < m:
    //return 2, if > m:
    long long mul = 1;

    for(int i= 1 ; i<= n ; i++){
        mul = mul * mid;
        if(mul > m) return 2;
    }
    if(mul == m)    return 1;

    return 0;
}

int optimal(int n , int m){

    int low = 0 , high = m;

    //return 1, if == m:
    //return 0, if < m:
    //return 2, if > m:

    while (low <= high) {
        int mid = (low + high) / 2;
        int ans = func(m,n,mid);
        if (ans == 1) {
            return mid;
        }
        else if (ans == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;

} 

int main(){

    int n = 3, m = 27;
    int ans = optimal(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;

    return 0;
}