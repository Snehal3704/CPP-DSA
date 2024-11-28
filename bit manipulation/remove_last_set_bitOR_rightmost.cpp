#include<bits/stdc++.h>

using namespace std;
//set bit = rightmost first bit having 1

int setbit(int n, int i){
     // Creating the mask by shifting
    // 1 to the left by i positions
    // This creates a mask where only the ith
    // bit is set to 1.
    int mask = 1 << i;
    
    // Toggling the ith bit of n using
    // bitwise XOR with the mask
    // This toggles the ith bit of n by
    // performing a bitwise XOR
    // operation with the mask.
    return n ^ mask; 
}


int main(){

    int n = 13;
    int i = 2;
    cout << setbit(n,i);


}