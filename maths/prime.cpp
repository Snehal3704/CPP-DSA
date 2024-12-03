#include<bits/stdc++.h>

using namespace std;

bool checkPrime(int n){
    int cnt = 0;

    for(int i = 1 ; i< sqrt(n) ; i++){

        if(n % i == 0){
            cnt++;

            //counting 2nd divisor
            if( n / i != i){
                cnt++;
            }
        }

        if(cnt > 2) break;
        

    }

    if(cnt == 2)    return true;
    else return false;
}

int main(){
    int n = 12;
    cout<< checkPrime(n);

}