#include<bits/stdc++.h>

using namespace std;

double myPow(double x, int n) {
        double ans = 1;
        bool sign = true;

        long long N = n;
        if( N < 0){
            N = -1 * N;
            sign = false;
        }  

        while( N > 0){

            if( (N & 1) != 0){
                ans = ans * x;
                N = N - 1;
            }
            else{
                N = N >> 1;
                x = x * x;
            }
        }

        if(sign)    return ans;
        else return 1 / ans;

    }

int main(){

    int n = -2;
    double x = 2;

    cout<< myPow(x,n);

}