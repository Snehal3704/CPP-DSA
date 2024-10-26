#include<iostream>
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

node* convert_arr_to_ll(int arr[]){

    
    node* head= new node(arr[0]);
    node* temp=head;
    for(int i=1;i<5;i++)
    {
        node* temp2= new node(arr[i]);
        temp->next=temp2;
        temp=temp2;
    }

    return head;
}

node* brute(node* head){

    node* temp = head;
    int len = 0;

    while(temp){
        len++;
        temp = temp->next;
    }

    int mid = (len) / 2 + 1;

    temp = head;

    while(temp){
        mid = mid - 1;

        // Check if the middle
        // position is reached.
        if (mid == 0){
            // break out of the loop
            // to return temp
            break;
        }
        // Move temp ahead
        temp = temp->next;
    }

    return temp;

}

node* optimal(node* head){

    //if len == odd
    //then fast will be pointing at last node
    //and len == even then fast will be pointing at null

    node* fast = head;
    node* slow = head;

    while(fast !=NULL and fast->next != NULL){
        // Move slow one step.
        slow = slow->next; 
         // Move fast two steps.
        fast = fast->next->next;

    }
}




int main()
{
    int arr[5]={1,2,3,4,5};
    node* head =convert_arr_to_ll(arr);
    
    node* temp = optimal(head);

    cout<<temp->value;

    return 0;

}