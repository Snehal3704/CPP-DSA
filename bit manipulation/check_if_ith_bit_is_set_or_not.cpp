#include<bits/stdc++.h>

using namespace std;

bool check_using_leftshit(int n , int i){

    if( n & (1 << i) !=0)   return true;
    else return false;
}

bool check_using_rightshift(int n , int i){
    if((n >> i) & 1 == 1)   return true;
    else return false;
}

int main(){

    int n = 13;
    int i = 1;
    cout<< check_using_rightshift(n,i);
}