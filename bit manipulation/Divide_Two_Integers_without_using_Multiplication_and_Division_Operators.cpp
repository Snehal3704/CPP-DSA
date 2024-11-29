#include<bits/stdc++.h>

using namespace std;

int getdivison(int dividend , int divisor){

    int sum = 0 ,cnt = 0;

    while(sum + divisor <= dividend){
        // cout<< cnt<<endl;
        // cout<<sum <<" ";
        sum = sum + divisor;
        cnt++;
    }
    return cnt;
}

int optimal(int divident , int divisor){
    if(divident == divisor) return 1;

    bool sign = true;

    if(divident < 0 and divisor >=0)    sign = false;
    if(divisor < 0 and divident >= 0)   sign = false;

    int n  = abs(divident);
    int d = abs(divisor);
    int ans =0;
    

    while( n >= d){

        int cnt =0;

        while( n >= d << (cnt + 1 )){
            cnt++;
        }

        ans = ans + (1 << cnt);
        n = n - (d <<cnt);

    }

    if(ans == (1 << 31) && sign){
        return INT_MAX;
    }
    if(ans == (1 << 31) && !sign){
        return INT_MIN;
    }

    return sign ? ans : -ans;
}

int main(){
    int dividend = 22;
    int divisor = 3;

    cout << optimal(dividend,divisor);


}