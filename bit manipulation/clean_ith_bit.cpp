#include<bits/stdc++.h>

using namespace std;

int clearbit(int n, int i){
    int need = ~(1 << i);

    return ( n  & need);
}


int main(){

    int n = 13;
    int i = 2;
    cout << clearbit(n,i);


}