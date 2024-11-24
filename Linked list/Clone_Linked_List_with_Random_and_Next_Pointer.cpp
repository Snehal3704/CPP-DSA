                                
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Node class to represent
// elements in the linked list
class Node {
public:
    // Data stored in the node
    int data;           
     // Pointer to the next node
    Node *next;        
    // Pointer to a random
    // node in the list
    Node *random;       

    // Constructors for Node class
    Node() : data(0), next(nullptr), random(nullptr){}; 
    Node(int x) : data(x), next(nullptr), random(nullptr) {} 
    // Constructor with data,
    // next, and random pointers
    Node(int x, Node *nextNode, Node *randomNode) :
            data(x), next(nextNode), random(randomNode) {}  
};


// Function to clone the linked list
Node *cloneLL(Node *head){
    Node* temp = head;
    // Create an unordered_map to map original
    // nodes to their corresponding copied nodes
    unordered_map<Node*, Node*> mpp;

    // Step 1: Create copies of each node
    // and store them in the map
    while(temp != NULL){
        // Create a new node with the
        // same data as the original node
        Node* newNode = new Node(temp->data);
        // Map the original node to its
        // corresponding copied node in the map
        mpp[temp] = newNode;
        // Move to the next node in the original list
        temp = temp->next;
    }
    
    temp = head;
    // Step 2: Connect the next and random
    // pointers of the copied nodes using the map
    while(temp != NULL){
        // Access the copied node corresponding
        // to the current original node
        Node* copyNode = mpp[temp];
        // Set the next pointer of the copied node
        // to the copied node mapped to the
        // next node in the original list
        copyNode->next = mpp[temp->next];
        // Set the random pointer of the copied node
        // to the copied node mapped to the
        // random node in the original list
        copyNode->random = mpp[temp->random];
        // Move to the next node
        // in the original list
        temp = temp->next;
    }
    
    // Return the head of the
    // deep copied list from the map
    return mpp[head];
}

Node* optiaml(Node* head){

    Node* temp = head;

    //inserting copied nodes in between the given linkedlist
    while(temp !=NULL){
        Node* newnode = new Node(temp->data);
        newnode->next = temp->next;
        temp->next = newnode;

        //as we are adding new nodes between the given nodes so the newnode is at temp->next so for going to next given node we have to go to temp->next->next

        temp = temp->next->next;
    }

    temp = head;

    //connect the random pointers
    while(temp != nullptr){
        Node* copynode = temp->next;

        // If the original node
        // has a random pointer
        if(temp->random){   
             // Point the copied node's random to the
             // corresponding copied random node
            copynode->random = temp->random->next; 
        }
        else{
             // Set the copied node's random to
             // null if the original random is null
            copynode->random = NULL;   
        }

        // Move to the next original node
        temp = temp->next->next;

    }

    //connect the next or intermidiate pointer with each of them

    temp = head;
    // Create a dummy node
    Node* dummyNode = new Node(-1);   
    // Initialize a result pointer
    Node* res = dummyNode; 
    while( temp!= nullptr){

        //linking the res to the newly copied node
        res->next = temp->next; //temp->next = copied node

        //move res pointer for further development of the newly created linkedlist
        res= res->next;

        // Disconnect and revert back to the
        // initial state of the original linked list,previously temp->next was pointing new node and newnode->next is pointing to the 2nd node of the given linked list

        temp->next = temp->next->next;
        temp = temp->next;



    }
        //newhead will always be  the dummynode->next

        return dummyNode->next;
}


// Function to print the cloned linked list
void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
         // Move to the next node
        head = head->next;  
    }
}

// Main function
int main() {
    // Example linked list: 7 -> 14 -> 21 -> 28
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    // Clone the linked list
    Node* clonedList = optiaml(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}
                                
                            