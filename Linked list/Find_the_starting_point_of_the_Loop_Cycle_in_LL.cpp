#include<bits/stdc++.h>

using namespace std;

class node{

    public:
    int data;
    node* next;

    node(int x){
        data=x;
        next = nullptr;
    }

    node(int x ,node* next1){
        data=x;
        next=next1;
    }

};
node* brute(node* head){
    if(head == NULL)    return nullptr;

    unordered_map<node*,int> visited;

    node* temp = head;

    while(temp != NULL){

        if(visited[temp]==true){
            return temp;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return nullptr;
}

node* optimal(node* head){

    node* slow = head;
    node* fast = head;

    while( fast !=nullptr and fast->next != nullptr){

        slow = slow-> next;
        fast = fast->next->next;

        if(slow == fast){
        // Reset the slow pointer
             // to the head of the list
            slow = head; 

            // Phase 2: Find the first node of the loop
            while (slow != fast) {
                
                // Move slow and fast one step
                // at a time
                slow = slow->next;  
                fast = fast->next;  

                // When slow and fast meet again,
                // it's the first node of the loop
            }
            
            // Return the first node of the loop
            return slow;  
        }
    }
    
     // If no loop is found, return NULL
    return NULL; 
}
    


int main(){

    // Create a sample linked list with a loop
    node* node1 = new node(1);
    node* node2 = new node(2);
    node1-> next = node2;
    node* node3 = new node(3);
    node2-> next = node3;
    node* node4 = new node(4);
    node3->next = node4;
    node* node5 = new node(5);
    node4-> next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    node* head = node1;

    // Detect the loop in the linked list
    node* loopStartnode = brute(head);

    if (loopStartnode) {
        cout << "Loop detected. Starting node of the loop is: "<< loopStartnode->data << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}