#include<bits/stdc++.h>

using namespace std;

int xorTill(int n){
    // Check if n is
    // congruent to 1 modulo 4
    if( n % 4 == 1) return 1;
    // Check if n is congruent
    // to 2 modulo 4
    else if( n % 4 == 2)    return n +1;
    else if( n % 4 == 3)    return 0;
    else    return n;

}

int xorInRange(int L, int R){
    // xoring 1->l-1 and xoring 1->R;
    //as we know xor of same number will cancle out so we get our answer
    //ex
    
    // (1^2^3) ^ (1^2^3^4^5^6^7^8)  =4^5^6^7^8
    return xorTill(L - 1) ^ xorTill(R);
}

int main() {
    int L = 3;
    int R = 19;
    int ans = xorInRange(L, R);
    cout << "XOR of of Numbers from " << L;
    cout << " to " << R << ": "<< ans << endl;
    return 0;
}