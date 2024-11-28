#include<bits/stdc++.h>

using namespace std;

int convert2binary(int n){

    string res = " ";
    while( n > 0){

        if(n % 2 == 1)  res+='1';
        else res+='0';

        n  = n / 2;

    }

    reverse(res.begin(),res.end());
    return stoi(res);
}

void setbit(int &n, int i){
    n = (n | (1 << i));
    cout<< n;
}

int main(){

    int n = 13;
    int i = 2;
    setbit(n,i);


}