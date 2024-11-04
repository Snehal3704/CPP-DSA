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

void print(node* head){
    node* temp = head;
    while(temp){
        cout<<temp->value <<" ";
        temp=temp->next;
    }
}

node* convert_arr_to_ll(vector<int>arr1){

    int n = arr1.size();
    node* head= new node(arr1[0]);
    node* temp=head;
    for(int i=1;i<n;i++)
    {
        node* temp2= new node(arr1[i]);
        temp->next=temp2;
        temp=temp2;
    }

    return head;
}

node* addTwoNumbers(node* first_head,node* second_head){

    node* t1 = first_head;
    node* t2 = second_head;

    node *dummy = new node(-1); 
        node *temp = dummy; //for expanding the answer list

    int carry=0;
    int sum =0;

    while(t1!= NULL and t2 != NULL){
        sum = carry;

        if(t1 !=nullptr){
            sum += t1->value;
            t1=t1->next;
        }   

        if(t2 != nullptr) {
            sum += t2->value;
            t2=t2->next;
        }

     node* newnode =new node(sum % 10);

     carry = sum / 10;

     //linking the answer last node to the newnode
     temp->next = newnode;
     //moving the last pointer for again adding new nodes
     temp=temp->next;
        
    }

    if(carry){
        node* newnode = new node(carry);
        temp->next=newnode;
    }

    return dummy->next;
}

int main()
{
    vector<int> arr1={3,5};
    vector<int> arr2={4,5,9,9};
    node* first_head =convert_arr_to_ll(arr1);
    node* second_head = convert_arr_to_ll(arr2);
   
    print(addTwoNumbers(first_head,second_head));

    return 0;

}