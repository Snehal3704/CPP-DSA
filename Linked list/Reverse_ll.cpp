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

node* reverseList(node* head) {
        node* curr = head;

        node* prev = NULL;

        while(curr != NULL){
            node* nextptr  =curr-> next;

            curr->next = prev;

            prev = curr;

            curr= nextptr; 
        }
        return prev;
    }

int main()
{
    int arr[5]={1,2,3,4,5};
    node* head =convert_arr_to_ll(arr);
    
    print(reverseList(head));

    

    return 0;

}