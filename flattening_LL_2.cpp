#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *next;
    node *child;

    // Constructors to initialize the
    // data, next, and child pointers
    node() : data(0), next(nullptr), child(nullptr) {};
    node(int x) : data(x), next(nullptr), child(nullptr) {}
    node(int x, node *nextnode, node *childnode) :
                    data(x), next(nextnode), child(childnode) {}
};

// Function to convert a vector to a linked list
node* convertArrToLinkedList(vector<int>& arr){
    // Create a dummy node to serve as
    // the head of the linked list
    node* dummynode = new node(-1);
    node* temp = dummynode;

    // Iterate through the vector and
    // create nodes with vector elements
    for(int i = 0; i < arr.size(); i++){
        // Create a new node
        // with the vector element
        temp->child = new node(arr[i]); 
        // Move the temporary pointer
        // to the newly created node
        temp = temp->child; 
    }
    // Return the linked list starting
    // from the next of the dummy node
    return dummynode->child; 
}

//t.c = O(n)-->recursion depth + o(n1+n2)-->for merging
//overall = O(2NM)
//s.c = O(n)-->recursive stack
node* merge_two_list(node* head1, node* head2) {
    // Dummy node to build the merged list
    node* dummynode = new node(-1);
    node* temp = dummynode;

    // Merge both lists by comparing data
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            temp->child = head1;
            head1 = head1->child;
        } else {
            temp->child = head2;
            head2 = head2->child;
        }
        temp = temp->child;
    }

    // Append remaining nodes from head1
    while (head1 != nullptr) {
        temp->child = head1;
        head1 = head1->child;
        temp = temp->child;
    }

    // Append remaining nodes from head2
    while (head2 != nullptr) {
        temp->child = head2;
        head2 = head2->child;
        temp = temp->child;
    }

    // Ensure no dangling pointers
    temp->child = nullptr;

    return dummynode->child;
}


node* flatterning(node* head){

    if(head == NULL or head->next == NULL)  return head;

    node* mergehead = flatterning(head->next);
    head->next = nullptr; // Disconnect next to prevent cyclic links

    return merge_two_list(head,mergehead);

    
}

// Print the linked list by
// traversing through child pointers
void printLinkedList(node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

// Print the linked list
// in a grid-like structure
void printOriginalLinkedList(node* head, int depth) {
    while (head != nullptr) {
        cout << head->data;

        // If child exists, recursively
        // print it with indentation
        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars
        // for each level in the grid
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main() {
    // Create a linked list with child pointers
    node* head = new node(3);
    //head->child = new node(14);
    
    head->next = new node(2);
    head->next->child = new node(10);
    
    head->next->next = new node(1);
    head->next->next->child = new node(7);
    head->next->next->child->child = new node(11);
    head->next->next->child->child->child = new node(12);
    
    head->next->next->next = new node(4);
    head->next->next->next->child = new node(9);

    head->next->next->next->next = new node(5);
    head->next->next->next->next->child = new node(6);
    head->next->next->next->next->child->child = new node(8);

    // Print the original
    // linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // Flatten the linked list
    // and print the flattened list
    node* flattened = flatterning(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}
