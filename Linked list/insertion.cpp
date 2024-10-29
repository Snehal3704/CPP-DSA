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

node* insertion(node* head , int k, int ele){

    if(head == nullptr) return head;

    if(k==1)    return new node(ele,head);

    int cnt =0;
    node* temp = head;

    while(temp){
        cnt++;


        if(cnt == k - 1){

            node *x = new node(ele);
            //always do connection then broke the past connection
            x->next = temp->next;
            temp->next = x;
            break;
        }

        temp = temp->next;
    }
    return head;
}


int main()
{
    int arr[5]={1,2,3,4,5};
    node* head =convert_arr_to_ll(arr);
    int ele = 11;
    int k =1;
    print(insertion(head,k, ele));

    return 0;

}