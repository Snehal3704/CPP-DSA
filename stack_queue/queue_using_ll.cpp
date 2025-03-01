#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int value;
    node* next;

    node(int x) {
        value = x;
        next = NULL;
    }
};

class que {
private:
    node* start;
    node* end;
    int curr_size;

public:
    que() {
        start = nullptr;
        end = nullptr;
        curr_size = 0;
    }

    void Enqueue(int x) {
        node* temp = new node(x);

        if (curr_size == 0) {
            start = temp;
            end = temp;
        } else {
            end->next = temp;
            end = temp;
        }
        curr_size++;
    }

    void Dequeue() {
        if (curr_size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }

        node* temp = start;
        start = start->next;
        delete temp;
        curr_size--;

        if (curr_size == 0) {
            end = nullptr;
        }
    }

    void display() {
        node* temp = start;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    que q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    cout << "Queue: ";
    q.display();

    q.Dequeue();
    cout << "After Dequeue: ";
    q.display();

    return 0;
}
