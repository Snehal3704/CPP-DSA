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
    
};

void print(node* head){
    node* temp = head;
    while(temp){
        cout<<temp->value;
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
}

node* deletion(node* head , int k){

    if( head == nullptr)    return head;
    
    if(k==1){

        node* temp = head;
        head= head->next;
        delete temp;

        return head;
    }

    node* temp = head;
    node* prev= nullptr;

    int cnt = 0;

    while(temp != NULL){
        cnt++;

        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;

        }
        prev=temp;
        temp = temp->next;
    }

    return head;

}

int main()
{
    int arr[5]={1,2,3,4,5};
    node* head =convert_arr_to_ll(arr);
    int k =3;
    print(deletion(head,k));

    return 0;

}