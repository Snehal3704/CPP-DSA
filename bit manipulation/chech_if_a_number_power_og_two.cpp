#include<bits/stdc++.h>

using namespace std;
//set bit = rightmost first bit having 1

int check(int n){
    if(n & (n-1) == 0)  return true;
    else return false;
}


int main(){

    int n = 13;
    
    cout << check(n);


}