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

int convert2decimal(int n){
    int res = 0;
    int pow =1;

    while( n > 0 ){

        int num = n % 10;
        res = res + ( pow * num );
        n = n / 10;
        pow *=2;

    }
    return res;
}

int main(){
    int n = 13;

    cout<< convert2binary(n);
    cout<<endl;

    cout<< convert2decimal(convert2binary(n));
}
