#include<bits/stdc++.h>
//// ALWAYS TRY TO GO TO THE NODE BEFORE THE ONE WE NEED TO REMOVE 
// THAT WAY WE CAN DIRECTLY CONNECT THE PREVIOUS NODE TO THE NEXT NODE OF THE ADDRESSED ONE

using namespace std;

class node {
    public:
    int value;
    node* next;

    node(int x){
        value=x;
        next=NULL;
    }
    
};

void print(node* head){
    node* temp = head;
    while(temp){
        cout<<temp->value <<" ";
        temp=temp->next;
    }
}

node* convert_arr_to_ll(int arr[] , int n){

    
    node* head= new node(arr[0]);
    node* temp=head;
    for(int i=1;i< n;i++)
    {
        node* temp2= new node(arr[i]);
        temp->next=temp2;
        temp=temp2;
    }

    return head;
}
/*
t.c = O(len) + O(len - n)
in worst it can be O(2len);
s.c = O(1)
*/
node* brute(node* head, int n) {
        node* traversal = head;
        int size = 0;

        // Calculate the size of the list
        while (traversal != nullptr) {
            size++;
            traversal = traversal->next;
        }

        // If the node to remove is the head node
        if (n == size) {
            node* newHead = head->next;
            delete head;
            return newHead;
        }

        // Calculate the position of the node just before the one to remove
        int need = size - n;
        traversal = head;

        // Traverse to the node just before the one we need to delete
        for (int i = 1; i < need; i++) {
            traversal = traversal->next;
        }

        // Remove the nth node from the end
        node* deleteNode = traversal->next;
        traversal->next = deleteNode->next;
        delete deleteNode;

        return head;
    }

   // OPTIMAL

// letting 'fast' go ahead n steps and then make 'slow' start from head and 
// move fast and slow both by 1 step until fast reaches null 

// ALWAYS TRY TO GO TO THE NODE BEFORE THE ONE WE NEED TO REMOVE 
// THAT WAY WE CAN DIRECTLY CONNECT THE PREVIOUS NODE TO THE NEXT NODE OF THE ADDRESSED ONE

// Time Complexiyt = O(N)
// Space Complexiyt = O(1) 

node* optimal(node* head, int n){
    if(n <= 0) return head;

    node* fast = head ; 

    for(int i=0; i<n; i++){
        // Means n is greater then the length of the LL 
        if(fast == nullptr) return head; 
        fast = fast->next;
    } 

    node* slow = head ;

    // Means n is at head from the back 
    if(fast == nullptr){
        head = head->next; 
        slow->next = nullptr; 
        delete slow; 
        return head; 
    }

    // Moving 1 step at a time 
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    // deleting the node and connecting the previous and the next one 
    node* delnode = slow->next;
    slow->next = slow->next->next; 
    delete delnode; 

    return head; 
}

int main()
{
    int arr[6]={1,2,3,4,5,6};
    int n = 6;
    node* head =convert_arr_to_ll(arr,n);
   
    print(brute(head,2));

    return 0;

}