#include<iostream>

using namespace std;

int main()
{

class queue{
    int *arr;
    int front,rear,count,size;
    public:
    queue(){
      arr = new int[16];
      front = -1;
      rear = -1;
      size = 0;
    }
    queue(int size) {
    ( * this).size = size;
    arr = new int[size];
    front = -1;
    rear= -1;
    count = 0;
  }
};


    return 0;
}
