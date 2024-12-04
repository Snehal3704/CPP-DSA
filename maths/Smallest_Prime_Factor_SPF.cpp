#include<bits/stdc++.h>
using namespace std;
// Generate the smallest prime factor (SPF) for numbers up to `maxLimit`
vector<int> getsieve(int maxLimit) {
    vector<int> spf(maxLimit + 1); // Smallest Prime Factor array
    for (int i = 0; i <= maxLimit; i++) {
        spf[i] = i; // Initialize each number as its own smallest prime
    }

    for (int i = 2; i * i <= maxLimit; i++) {
        if (spf[i] == i) { // Check if `i` is prime
            for (int j = i * i; j <= maxLimit; j += i) {
                if (spf[j] == j) { // Only update if it hasn't been updated
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

vector<int> primeFactor(int n){
    vector<int> ans;
    for(int i = 2 ; i< sqrt(n) ; i++){

        if(n % i == 0){

        
        //skkiping all factor of i ex = 4,6,8 etc
        while( n % i ==0){
            ans.push_back(i);
            n = n / i;
        }

        }  
    }
    //after divison will at last have an prime number and we have to add it to the answer
    if( n != 1) ans.push_back(n);
    return ans;

}

vector<int> spf(int n){
    

    vector<int> prime = getsieve(n);

    return prime;

    

}

int main(){
    int n = 132;

    vector<int> ans = spf(n);

    for(int i= 0 ; i< ans.size() ; i++){
        cout << ans[i] <<" ";
    }


}