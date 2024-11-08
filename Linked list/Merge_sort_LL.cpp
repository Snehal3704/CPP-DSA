#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int value;
    node* next;

    node(int x){
        value=x;
        next=NULL;
    }
    node(int x2,node* next1){
        value = x2;
        next = next1;

    }
};

// node* insertHead(node* head,int ele){
//     node* tenp = new node(ele,head);
//     return tenp;
// }

void print(node* head){
    node* temp = head;
    while(temp){
        cout<<temp->value <<" ";
        temp=temp->next;
    }
}

node* convert_arr_to_ll(int arr[],int n){

    
    node* head= new node(arr[0]);
    node* temp=head;
    for(int i=1;i<n;i++)
    {
        node* temp2= new node(arr[i]);
        temp->next=temp2;
        temp=temp2;
    }

    return head;
}

node* brute(node* head){
    vector<int> temp;

    node* trav = head;

    // Traverse the linked list and
    // store node values in the vector
    while(trav){
        temp.push_back(trav->value);
        trav=trav->next;
    }

    sort(temp.begin(),temp.end());

    trav = head;

    for(int i = 0; i < temp.size(); i++){
        // Update the node's data
        // with the sorted values
        trav->value = temp[i]; 
        // Move to the next node
        trav = trav->next; 
    }
    
    // Return the head of the
    // sorted linked list
    return head; 


}

node* merge(node* left ,node* right){
    node* t1 =left;
    node* t2 =right;

    node* dummynode = new node(-1);
    node* temp =dummynode;

    while(t1 != NULL and t2!= NULL){

        if(t1->value<= t2->value){

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
// modified Function to find the middle of a linked list
node* findMiddle(node* head){
    // If the list is empty or has only one node
    // the middle is the head itself
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Initializing slow and fast pointers
    node* slow = head;
    node* fast = head;
    node* prev = NULL;

    
    while (fast != nullptr && fast->next != nullptr) {

        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(fast == NULL)
    return prev;
    
    return prev->next;
}

node* mergesort(node* head){

    // Base case: if the list is empty or has only one node
    // it is already sorted, so return the head
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Find the middle of the list using the findMiddle function
    node* middle = findMiddle(head);

    // Divide the list into two halves

    //right side
    node* right = middle->next;
    middle->next = nullptr;

    //left side
    node* left = head;

    // Recursively sort the left and right halves
    left = mergesort(left);
    right = mergesort(right);

    return merge(left,right);

}

int main()
{
    int arr[6]={21,2,13,32,9,17};
    int n = 6;
    node* head =convert_arr_to_ll(arr,n);
   
    print(mergesort(head));

    return 0;

}