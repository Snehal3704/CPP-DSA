#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){

    if(b == 0){
        return a;
    }
    
    // we cannot do gcd(a % b , b)    as when this goes the the first number gets smaller than the second one which is not valid for equaliddian theorem

    // but if we go gcd(b , a %b) this ensures that the first number will be always greater than the second number

    /*
    For example, consider a = 8 and b = 4. The first call is gcd(8 % 4, 4) → gcd(0, 4). This works because the remainder is 0, and the base case returns b = 4.

    However, for inputs like a = 4 and b = 8, the sequence becomes:

    gcd(4 % 8, 8) → gcd(4, 8) → infinite recursion! This is because a % b equals a when a < b, and the arguments never reduce.
    */
    int ans = gcd(b , a % b);
    return ans;
}

int main()
{
	int a = 4, b = 8;
	int g = gcd(a, b);
	int lcm = (a * b) / g;
	cout <<"The LCM of the two given numbers is "<<lcm;
}