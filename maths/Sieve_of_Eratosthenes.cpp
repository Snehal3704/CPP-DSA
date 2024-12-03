#include<bits/stdc++.h>

using namespace std;

void findAllPrimes(int n){
    
    //to store 2-> n numbers
    vector<int> arr(n + 1, 1);

    for(int i =2 ; i <= n ; i++){
        if(arr[i] == 1){
            for(int j = 2*i ; j <= n ; j+=i){
                arr[j] = 0;
            }
        }
    }

    for(int i = 2 ; i<= n ; i++){
        if(arr[i] == 1){
            cout<< i <<" "; 
        }
    }
    

}

int optimal(int n){

    if (n <= 2) {
            return 0; // No primes less than 2
    }
    vector<int> arr(n + 1 , 1);

    for(int i =2 ; i<= sqrt(n) ; i++){

        if(arr[i] == 1){

            for(int j = i*i ; j <= n ; j+=i){
                arr[j] = 0;
            }
            
        }
    }
    int cnt =0;
    for(int i = 2 ; i<= n ; i++){
        if(arr[i] == 1){
            cnt++; 
        }
    }
    return cnt;
}

int main() {
    int n = 132;
    cout << optimal(n);

    

    return 0;
}