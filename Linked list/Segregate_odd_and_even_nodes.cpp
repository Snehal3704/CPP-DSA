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

node* brute(node* head){

    if(head == NULL or head->next == NULL ) return head;
    node* temp = head;
    
    vector<int> ans;


    while(temp != NULL and temp->next != NULL){

        ans.push_back(temp->value);
        temp=temp->next->next;

    }

    if(temp)  ans.push_back(temp->value);

    temp = head->next;
    while(temp != NULL and temp->next != NULL){

        ans.push_back(temp->value);
        temp=temp->next->next;

    }
    
    if(temp)  ans.push_back(temp->value);

    temp= head;
    int i=0;
    while(temp){
        temp->value = ans[i];
        i++;
        temp = temp->next;
    }

    return head;
}

/*Time Complexity: O(N) N is the number of Nodes in LinkedList. As we are traversing LinkedList once.

Space Complexity: O(1) We are just Manipulating the Links, not using any extra space.*/

node*  optimal(node* head){
    if (head == nullptr || head->next == nullptr)
            return head; // If the list is empty or has only one node, return as is
    node* odd = head;
    node* evenHead = head->next;
    node*even = head->next;

    while(even != nullptr and even->next !=nullptr){

        odd->next = odd->next->next;
        even->next = even->next->next;

        //odd and even are linked so go to their present location
        odd = odd->next;
        even = even->next;

    }
    // Connect the end of the odd list to the start of the even list
        odd->next = evenHead;
    return head;



}

int main()
{
    int arr[6]={1,2,3,4,5,6};
    int n = 6;
    node* head =convert_arr_to_ll(arr,n);
   
    print(optimal(head));

    return 0;

}