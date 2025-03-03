#include<bits/stdc++.h>

using namespace std;

class MinStack_pair{

    private:
    stack<pair<int,int>>st;

    public:

    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }
        else{

            int mini = st.top().second;
            mini =  min(val, mini);
            st.push({val,mini});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

class ans{
    private:
    stack<long long> st;
    long long mini;

    ans(){
        mini =LLONG_MAX; 
    }

    void push(int value){
        long long value = value; // Convert to long long

        if(st.empty()){
            mini = value;
            st.push(value);
        }else{
            if (value > mini) {
                st.push(value);
            } else {
                st.push(2 * value - mini);
                mini = value;
            }
        }
    }

    void pop() {
        if (!st.empty()) {
            long long x = st.top();
            st.pop();

            if (x < mini) { // If x is a modified value, restore mini
                mini = 2 * mini - x;
            }

            if (st.empty()) { // Reset mini when stack becomes empty
                mini = LLONG_MAX;
            }
        }
    }
    
    int top() {
        if (st.empty()) {
            return -1;
        }

        long long x = st.top();
        if (x >= mini) {
            return x;
        } else {
            return mini;
        }
    }
    
    int getMin() {
        if (st.empty()) {
            return -1;
        }
        return mini;
    }
};



int main() {
    MinStack_pair minStack;
    
    minStack.push(5);
    minStack.push(3);
    minStack.push(7);
    minStack.push(2);

    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 2

    minStack.pop();
    cout << "Minimum element after pop: " << minStack.getMin() << endl; // Output: 3

    minStack.pop();
    cout << "Top element: " << minStack.top() << endl; // Output: 3

    return 0;

}