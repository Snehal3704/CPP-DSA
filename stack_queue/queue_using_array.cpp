#include <iostream>

using namespace std;

class Queue {
    static const int size = 10;  // Static constant size
    int qu[size];  // Queue array
    int curr_size = 0;
    int start = -1;
    int end = -1;

public:
    void push(int x) {
        if (curr_size == size) {
            cout << "Cannot push anymore, queue is full" << endl;
            return;
        }

        if (curr_size == 0) {
            start = end = 0;
        } else {
            end = (end + 1) % size;
        }

        qu[end] = x;  // Store value
        curr_size++;   // Increment size
    }

    int pop() {
        if (curr_size == 0) {
            cout << "Cannot pop, queue is empty" << endl;
            return -1; // Indicating error
        }

        int ele = qu[start];

        if (curr_size == 1) {
            start = end = -1;  // Reset queue
        } else {
            start = (start + 1) % size;
        }

        curr_size--;  // Reduce size
        return ele;
    }

    int top() {
        if (curr_size == 0) {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        return qu[start];
    }

    int Size() {
        return curr_size;
    }
};

int main() {
    Queue q;  // Correct object creation

    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);

    cout << "The peek of the queue before deleting any element: " << q.top() << endl;
    cout << "The size of the queue before deletion: " << q.Size() << endl;
    cout << "The first element to be deleted: " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element: " << q.top() << endl;
    cout << "The size of the queue after deleting an element: " << q.Size() << endl;

    return 0;
}
