#include<bits/stdc++.h>

using namespace std;

int swapfn(int &a , int &b){

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

}

int main(){
 int a = 5;
 int b=6;

 cout<<" before swap \n";
 cout << a <<" "<<b <<"\n";
 cout<<"after swap\n";
    swapfn(a,b);
 cout << a <<" "<<b <<"\n";
 
}
