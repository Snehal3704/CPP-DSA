#include<iostream>
using namespace std;

class listnode {
public:
    int value;
    listnode *next;
    listnode *prev;

    listnode(int x) {
        value = x;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
public:
    listnode *head;

    DoublyLinkedList() {
        head = NULL;
    }

    // Function to insert a node at the end of the doubly linked list
    void insertNode(int x) {
        listnode *newNode = new listnode(x);
        if (head == NULL) {
            head = newNode;
        } else {
            listnode *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to display the doubly linked list
    void displayList() {
        listnode *temp = head;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
 
int main() {
    DoublyLinkedList dll;

    // Taking user-input values to insert into the doubly linked list
    int n, val;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        dll.insertNode(val);
    }

    // Displaying the doubly linked list
    cout << "Doubly Linked List: ";
    dll.displayList();

    return 0;
}
