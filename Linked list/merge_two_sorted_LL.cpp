
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;
    
    // Pointer to the next node in the list
    Node* next;

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to convert a vector to a linked list
Node* convertArrToLinkedList(vector<int>& arr){
    // Create a dummy node to serve
    // as the head of the linked list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Iterate through the vector and
    // create nodes with vector elements
    for(int i = 0; i < arr.size(); i++){
        // Create a new node with the vector element
        temp->next = new Node(arr[i]); 
        // Move the temporary pointer
        // to the newly created node
        temp = temp->next; 
    }
    // Return the linked list starting
    // from the next of the dummy node
    return dummyNode->next; 
}


Node* brute(Node* head1 ,Node* head2){

    vector<int> temp;

    Node* t1 =head1;
    Node* t2 =head2;

    while(t1 !=NULL or t2!= NULL){
        temp.push_back(t1->data);
        temp.push_back(t2->data);

        t1=t1->next;
        t2=t2->next;
    }

    sort(temp.begin(),temp.end());

    return convertArrToLinkedList(temp); 
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->data << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}

Node* optimal(Node* head1 ,Node* head2){
    Node* t1 =head1;
    Node* t2 =head2;

    Node* dummynode = new Node(-1);
    Node* temp =dummynode;

    while(t1 != NULL and t2!= NULL){

        if(t1->data <= t2->data){

            //linking temp to the answer nodes location
            temp -> next = t1;
            //moving the traversal pointer for head1
            t1=t1->next;
        }
        else{
            //linking temp to the answer nodes location
            temp -> next = t2;
            //moving the traversal pointer for head2
            t2=t2->next;
        }
        //again moving temp by one place for again linking new nodes
        temp = temp->next;
    }

    while(t1 != NULL){
        //linking temp to answer node
        temp->next = t1;
        //moving t1 for traverse the left nodes if t2 is finised
        t1 = t1->next;
        temp = temp->next;
        
    }
    while(t2 != NULL){
        temp->next = t2;
        t2 = t2->next;
        temp = temp->next;
        
    }

    return dummynode->next;

}
int main() {
    // Example Linked Lists
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Node* mergedList = optimal (list1, list2);

    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;

}

