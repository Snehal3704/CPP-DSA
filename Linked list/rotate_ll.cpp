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

node* rotate_ll(node* head , int k){

    node* temp = head;
    node* tail = head;

    int len = 0;
    


    while(tail ->next !=NULL){
        len++;
        tail = tail -> next;
    }

    if(k % len == 0) return head;

    k = k % len;
    int need = len - k;

    while(need >0){
        need--;
        temp = temp->next;
    }

    node* newhead = temp->next;
    temp -> next = NULL;

    tail->next = head;
    
    return newhead;

}


int main()
{
    int arr[5]={1,2,3,4,5};
    node* head =convert_arr_to_ll(arr);
    int k = 2;
    
    print(rotate_ll(head,k));

    

    return 0;

}