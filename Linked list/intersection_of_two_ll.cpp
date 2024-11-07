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

node* brute(node* first_head,node* second_head){
    node* t1 = first_head;
        node* t2 = second_head;

        unordered_set<node*>st;

        while(t1 != NULL){
            st.insert(t1);
            
            t1= t1->next;
            
        }

        while(t2 != NULL){
            if(st.find(t2) !=st.end()){
                return t2;
            }
            t2 = t2 -> next;
        }

        return NULL;
}



node* better(node* first_head, node* second_head){
    node* t1 = first_head;

    node* t2 = second_head;
    

    int len1 = 0,len2 = 0;
        while(t1 != NULL || t2!= NULL) {
            if(t1 != NULL) {
                len1++; t1 = t1->next;
            }
            if(t2 != NULL) {
                len2++; t2 = t2->next;
            }
            
        }
        int diff = abs(len1 - len2);

        t1 = first_head;
        t2 = second_head;

        if(len1 < len2){
            while(diff > 0){
                t2= t2->next;
                diff--;
            }
        }
        else{
            while (diff > 0){
                t1 = t1->next;
                diff--;
            }
            
        }

        while(t1 != NULL and t2 != NULL){
            if(t1 == t2){
                return t1;

            }
            t1 = t1->next;
            t2=t2->next;
        }

        return NULL;

    

}

// Time Complexity = O(N + M)
// Space Complexity = O(1) 

// Moving up and down pointers till nullptr 
// once one of them reaches null(happens only when size of two LL are diff)
// we make that pointer point to the head of the other LL 

// this way if the smaller LL has D less steps than Larger LL 
// then when that pointer reaches null, the other pointer will be D steps behind him 
// and if we bring the pointer back to other LL's head then 
// As we moving them simaltaneously, 
// the other pointer will reach null and then shifts to smaller LL's head
// on the other hand our pointer will reach the node in the larger LL which is D steps further from its head 

// and they both will point the same node if counted backwards from null 


//      down
//  A -> B -> C 
//              -> D -> E -> F -> G
//       H -> I
//      up

// now we can compare them 

node* optimal(node* head1 , node* head2){
    
    node* t1 =head1;
    node* t2 =head2;

    while(t1 != t2){

        t1 = t1->next;
        t2 = t2->next;

        //same two linkedlist
        if(t1 ==  t2)   return t1;

        if(t1== NULL)  t1 = head2;
        if(t2==NULL)    t2 = head1;


    }
    return t1;
}

int main()
{
    vector<int> arr1={4,1,8,4,5};
    //vector<int> arr2={5,6,1,8,4,5};
    node* first_head =convert_arr_to_ll(arr1);
    node* second_head = new node(5);
    node* temp= new node(6);
    node* temp2 = new node(1);

    second_head->next=temp;
    temp->next=temp2;
    temp2->next = first_head->next->next;
   
    node* ans = optimal(first_head,second_head);
    if(ans == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<ans->value<<endl;
    return 0;
}