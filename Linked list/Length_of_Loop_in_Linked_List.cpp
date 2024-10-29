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

int brute(node* head){
    // Hashmap to store visited
    // nodes and their timer values
    unordered_map<node*,int> mpp;

    int cnt=0;

    node* temp = head;

    while(temp!= nullptr){
    
        if(mpp.find(temp) != mpp.end()){

        // Return the length of the loop
        return cnt - mpp[temp];

        }

        // Store the current node and
        // its timer value in the hashmap
        mpp[temp] = cnt;

        temp=temp->next;
        cnt++;
    }

    // If traversal is completed and
    // we reach the end of the list (null)
    // means there is no loop
    return 0;
}

int optimal(node* head){
    node* slow = head;
    node* fast = head;

    while(fast !=nullptr and fast->next !=NULL){
        // Move slow one step
        slow = slow->next;     
        // Move fast two steps
        fast = fast->next->next;

        // Step 2: If the slow and fast pointers
        // meet, there is a loop
        if (slow == fast) {  // Loop detected
                //count the intersection point
                int cnt = 1;
                //move ahead of the fast and head intersection point
                slow = slow->next;
                
                // Count the nodes in the loop
                while (slow != fast) {
                    slow = slow->next;
                    cnt++;
                }
                return cnt;
            }
    }
}

int main(){

    // Create a sample linked
    // list with a loop
    
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* fourth = new node(4);
    node* fifth = new node(5);

    // Create a loop from
    // fifth to second
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // This creates a loop
    fifth->next = second; 

    int loopLength = optimal(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}