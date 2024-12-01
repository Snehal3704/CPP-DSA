#include<bits/stdc++.h>

using namespace std;

int findGcd( int n1 , int n2){
    // Continue loop as long as both
    // a and b are greater than 0

    while( n1 > 0 and n2 > 0){
        // If a is greater than b,
        // subtract b from a and update a

        if( n1 > n2){
            // Update a to the remainder
             // of a divided by b
            n1 = n1 % n2;
        }
        // If b is greater than or equal
        // to a, subtract a from b and update b
        else{
             // Update b to the remainder
            // of b divided by a
            n2 = n2 % n1;
        }

    }

    // Check if a becomes 0,
    // if so, return b as the GCD
    if(n1 == 0) {
        return n2;
    }
    // If a is not 0,
    // return a as the GCD
    return n1;
}

int main() {
    int n1 = 20, n2 = 15;
    
    // Find the GCD of n1 and n2
    int gcd = findGcd(n1, n2);

    cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd << endl;

    return 0;
}
