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
node* findkthnode(node* temp,int k){
    // Decrement K as we already
    // start from the 1st node
    k -= 1; 

    // Decrement K until it reaches
    // the desired position
    while(temp != NULL && k > 0){
        // Decrement k as temp progresses
        k--; 
        
        // Move to the next node
        temp = temp -> next; 
    }
    
    // Return the Kth node
    return temp; 
}
node* reverseLinkedList(node *head)
{
   // Initialize'temp' at
   // head of linked list
   node* temp = head;  
   
   // Initialize pointer 'prev' to NULL,
   // representing the previous node
   node* prev = NULL;  
   
   // Traverse the list, continue till
   // 'temp' reaches the end (NULL)
   while(temp != NULL){  
       // Store the next node in
       // 'front' to preserve the reference
       node* front = temp->next;  
       
       // Reverse the direction of the
       // current node's 'next' pointer
       // to point to 'prev'
       temp->next = prev;  
       
        // Move 'prev' to the current
        // node for the next iteration
       prev = temp;  
       
        // Move 'temp' to the 'front' node
        // advancing the traversal
       temp = front; 
   }
   
   // Return the new head of
   // the reversed linked list
   return prev;  
}

node* kReverse(node* head,int k){
    node* temp = head;
    node* prevnode = NULL;

    while(temp!= NULL){

        node* kthnode = findkthnode(temp,k);
        //if there is no kth node meaning ll is small
        if(kthnode ==NULL){


            break;
        }

        //remebering the kth next node for traversaing for other groups
        node* nextnode = kthnode->next;

        //the required group is separated
        kthnode->next= NULL;

        //reverseing the grp

        reverseLinkedList(temp);

        if(temp == head){
            head = kthnode;
        }
        else{

            prevnode ->next = kthnode;
        }

        //need for linking all the reversed groups
        prevnode = temp;

        temp = nextnode;
    }
    return head;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    int k =3;
    node* head =convert_arr_to_ll(arr,n);
   
    print(kReverse(head,k));

    return 0;

}