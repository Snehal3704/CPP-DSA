#include<bits/stdc++.h>

using namespace std;

vector<int> primeFactor(int n){
    vector<int> ans;
    for(int i = 2 ; i< sqrt(n) ; i++){

        if(n % i == 0){

        ans.push_back(i);
        //skkiping all factor of i ex = 4,6,8 etc
        while( n % i ==0){
            n = n / i;
        }

        }  
    }
    //after divison will at last have an prime number and we have to add it to the answer
    if( n != 1) ans.push_back(n);
    return ans;

}

int main(){
    int n = 780;
    vector<int> ans = primeFactor(n);
    for(auto it: ans){
        cout<< it<<" ";
    }

}