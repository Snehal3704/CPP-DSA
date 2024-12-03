#include <bits/stdc++.h>
using namespace std;

// Function to generate sieve of Eratosthenes
vector<int> getSieve(int n) {

    
    vector<int> prime(n + 1, 1); // Initialize all numbers as prime
    prime[0] = prime[1] = 0;     // 0 and 1 are not prime

    for (int i = 2; i * i <= n; ++i) { // Iterate up to sqrt(n)
        if (prime[i] == 1) {           // If 'i' is a prime number
            for (int j = i * i; j <= n; j += i) { // Mark multiples of 'i' as not prime
                prime[j] = 0;
            }
        }
    }
    return prime; // Return the sieve vector
}

// Function to count primes in given ranges
vector<int> countPrimes(vector<vector<int>> queries) {
    // Generate sieve up to a large limit
    vector<int> prime = getSieve(1000000);

    vector<int> ans;

    for (int i = 0; i < queries.size(); ++i) {
        int l = queries[i][0];
        int r = queries[i][1];

        int cnt = 0; // Counter for primes in the range

        for (int j = l; j <= r; ++j) { // Iterate from l to r
            if (prime[j] == 1) {       // Check if the number is prime
                cnt++;
            }
        }
        ans.push_back(cnt); // Store the count of primes for the range
    }

    return ans; // Return the result
}

vector<int> prefixsum(vector<vector<int>> queries){

    vector<int> primes = getSieve(10000000);
    vector<int> ans;
    int cnt = 0;

    for(int i =2 ; i< primes.size() ; i++){
        cnt = cnt + primes[i];
        primes[i] = cnt;
    }

    for(int i = 0 ; i < queries.size() ; i++ ){

    int l = queries[i][0];
    int r = queries[i][1];

    }

    cnt = 0; // Counter for primes in the range

    

    
}

int main() {
    int Q = 3; // Number of queries
    vector<vector<int>> queries = {{3, 10}, {8, 20}, {1, 5}}; // Query ranges

    cout << "Number of Queries: " << Q << endl;
    cout << "Queries: ";
    for (auto query : queries) {
        cout << "(" << query[0] << ", " << query[1] << ")  ";
    }
    cout << endl;

    // Get the result for each query
    vector<int> result = prefixsum(queries);

    cout << "Number of primes between the ranges: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
