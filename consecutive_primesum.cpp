#include<bits/stdc++.h>


using namespace std;

bool isPrime(int k) {
    if (k <= 1) {
        return false; // 0 and 1 are not prime numbers
    }

    // Optimize for efficiency by checking divisibility only up to the square root
    for (int i = 2; i <= sqrt(k); i++) {
        if (k % i == 0) {
            return false; // Found a divisor, not prime
        }
    }

    return true; // No divisors found, prime
}

void prime_series(int limit){
    int sum=0;
    int cnt=0;
    int maxi=0;
    int prime_sum=0;

    for(int ind=2 ; ind<=limit ; ind++){

        if(isPrime(ind)){

            maxi = max(maxi,ind);
            sum = sum + ind;

            if(isPrime(sum) and sum < limit){   //addition of two prime number not always be a prime number
                cnt++;
                prime_sum = sum;
                cout<<prime_sum<<" ";
            }
        
            
        }
        
    }
    
    cout<<endl <<cnt<<endl<<maxi;
}

int main() {
    int n;

    // cout << "Enter a number: ";
    // cin >> n;

    // int sum = 0;
    // vector<int> ans;
    
    prime_series(100);

    return 0;
}
