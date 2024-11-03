#include<bits/stdc++.h>
//// ALWAYS TRY TO GO TO THE NODE BEFORE THE ONE WE NEED TO REMOVE 
// THAT WAY WE CAN DIRECTLY CONNECT THE PREVIOUS NODE TO THE NEXT NODE OF THE ADDRESSED ONE

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

/*
    Time Complexity: O(N/2) The algorithm traverses the linked list using the Tortoise and Hare approach. The code increments both 'slow' and 'fast' pointers at different rates, effectively covering about half the list before reaching the midpoint, hence the time complexity of the algorithm is O(N/2) ~ O(N).

Space Complexity: O(1) The algorithm uses a constant amount of extra space regardless of the size of the input (linked list). It doesn't use any additional data structures in proportion to the input size. Thus, the space complexity is O(1) (constant space). 
*/

node* optimal(node* head ){
    if (!head || !head->next) {
            // If the list is empty or has only one node, return nullptr
            return nullptr;
    }

    node* slow= head;
    node* fast = head;
    node* prev = NULL;

    while(fast != NULL and fast->next !=NULL){
        
        prev = slow;
        slow = slow->next;
        fast = fast ->next->next;
        
    }

    prev-> next = slow->next;
        delete slow;
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