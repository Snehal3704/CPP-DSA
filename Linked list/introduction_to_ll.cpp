#include<bits/stdc++.h>

using namespace std;

class node{
    public:

    int data;
    node* nextptr;

    
    node(int data1){
        data =data1;
        nextptr = NULL;
    }



};

node* convert_arr_to_ll(vector<int> arr){

    node * head = new node(arr[0]);
    node* mover = head;

    for(int i=1 ; i< arr.size() ; i++){

        node* temp = new node(arr[i]);
        mover->nextptr = temp;
        mover = temp;
    }

    return head;


}

int length(node*head){
    
    int cnt =0 ;
    node* temp = head;

    while (temp != NULL){
        
        temp=temp->nextptr;
        cnt++;
    }

    return cnt;
}

int main(){

    
    vector<int> arr = {5,3,4,7,6,2};
    node* head = convert_arr_to_ll(arr);

    cout<< length(head);

    //traversaL
    // node* temp = head;

    // while (temp != NULL){
    //     cout<< temp->data << " ";
    //     temp=temp->nextptr;
    // }



    return 0;

}

