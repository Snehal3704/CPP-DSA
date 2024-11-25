#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list (forward direction)
    Node* back;     // Pointer to the backious node in the list (backward direction)

    // Constructor for a Node with both data, a reference to the next node, and a reference to the backious node
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with data, and no references to the next and backious nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
   // Create the head node with the first element of the array
    Node* head = new Node(arr[0]); 
   // Initialize 'back' to the head node

    Node* back = head;             
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array and set its 'back' pointer to the backious node
        Node* temp = new Node(arr[i], nullptr, back);
        // Update the 'next' pointer of the backious node to point to the new node

        back->next = temp;    
        // Move 'back' to the newly created node for the next iteration
   
       back = temp;         
     }
    // Return the head of the doubly linked list

    return head;  
}

// Function to print the elements of the doubly linked list
void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the current node
        cout << head->data << " "; 
        // Move to the next node
        head = head->next;         
    }
}

Node* deletehead(Node* head){
        
         if (!head) return nullptr;

            head->next->back = NULL;
            Node* newhead = head->next;
            delete head;
        
        return newhead;
}
    
Node* deleteAllOccurOfX(Node* head, int x) {

    Node* temp = head;
        
        while(temp != NULL){

            if(temp->data == x){
            // If the node is the head
                if (temp == head) {
                head = deletehead(head);
                temp = head; // Update temp to the new head
                }

                else{
                if (temp->next) temp->next->back = temp->back;
                if (temp->back) temp->back->next = temp->next;

                Node* toDelete = temp;
                temp = temp->next; // Move temp forward
                delete toDelete;   // Free the memory of the deleted node
                }

            }
            else{
            temp = temp->next; // Move to the next node
            }
                
        }
        
return head;

}



int main() {
    // Initialize an array and convert it to a doubly linked list
    vector<int> arr = {12, 5, 8, 7, 4, 5};
    Node* head = convertArr2DLL(arr);

    cout << "Original list: ";
    print(head);

    // Delete all occurrences of 5
    head = deleteAllOccurOfX(head, 5);

    cout << "List after removing all occurrences of 5: ";
    print(head);

    return 0;
}