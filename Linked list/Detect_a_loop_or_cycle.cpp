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

bool brute(node* head){

    if(head == NULL)    return false;

    unordered_map<node*,int> visited;

    node* temp = head;

    while(temp != NULL){

        if(visited[temp]==true){
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;

}

bool optimal(node* head){

    node* fast = head;
    node* slow = head;

    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow== fast) return true;
    }

    return false;
}

int main()
{
    int arr[5]={1,2,3,4,5};
    node* head =convert_arr_to_ll(arr);
    
    cout<< optimal(head);

    

    return 0;

}