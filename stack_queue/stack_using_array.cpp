#include<bits/stdc++.h>

using namespace std;

class st{
    int size;
  int * arr;
  int top;
  public:
    st() {
      top = -1;
      size = 1000;
      arr = new int[size];
    }

    void push(int x){
        if(top >= size) cout<<"stack is full";
        top++;
        arr[top] = x;
    }

    int pop(){
        int x = arr[top];
        top--;
        return x;
    }

    int Top() {
    return arr[top];
   }
   int Size() {
    return top + 1;
   }
};

int main(){
    st s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}
