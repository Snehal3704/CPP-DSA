#include<bits/stdc++.h>

using namespace std;

 class Node
        {
        public:
            int data;
            Node *next;
            
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

class Stack {
public:
    int stacksize = 0;
    Node* head = NULL;

    Stack() {
        // No code needed in the default constructor for a stack
    }

    int getSize() {
        return stacksize;
    }

    bool isEmpty() {
         if(head == NULL)
        return true;
        else 
        return false; // Corrected check for empty stack
    }

    void push(int data) {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
        stacksize++;
    }

    void pop() {
        if (head == NULL) {
            return; // Handle empty stack case
        }

        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        stacksize--;
    }

    int getTop() {
        if (head == NULL) {
            return -1; // Handle empty stack case
        }
        return head->data;
    }

    /*~Stack() { // Destructor to clean up memory
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }*/
};

int main()
{

    Stack s;
  s.push(10);
  s.push(2);

   s.pop();
  cout << "Stack size: " << s.getSize() << "\n";
  cout <<"Stack empty or not? "<<s.isEmpty()<<"\n";
  //cout << "stack's top element: " << s.pee() << "\n";
}