
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// node class represents a
// node in a linked list
class node {
public:
    // Data stored in the node
    int data;
    
    // Pointer to the next node in the list
    node* next;

    // Constructor with both data and
    // next node as parameters
    node(int data1, node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to convert a vector to a linked list
node* convertArrToLinkedList(vector<int>& arr){
    // Create a dummy node to serve
    // as the head of the linked list
    node* dummynode = new node(-1);
    node* temp = dummynode;

    // Iterate through the vector and
    // create nodes with vector elements
    for(int i = 0; i < arr.size(); i++){
        // Create a new node with the vector element
        temp->next = new node(arr[i]); 
        // Move the temporary pointer
        // to the newly created node
        temp = temp->next; 
    }
    // Return the linked list starting
    // from the next of the dummy node
    return dummynode->next; 
}

// Function to merge K sorted linked lists
node* brute(vector<node*> listArray){
    
    vector<int> arr;
    

    for(int i = 0 ; i< listArray.size() ; i++){
        node* temp = listArray[i];
        while(temp !=NULL){
            arr.push_back(temp->data);
            temp = temp -> next;
        }

    }
    // Sort the vector containing node
    // values in ascending order
    sort(arr.begin(), arr.end());

    // Convert the sorted vector back to
    // a linked list and return its head
    return convertArrToLinkedList(arr);
}

node* mergeTwoLists(node* node1, node* node2){

    node* temp1 = node1;
    node* temp2 = node2;
    node* dummynode = new node(-1);
    node* temp = dummynode;

    while(temp1 != NULL and temp2 != NULL){
        if(temp1->data >= temp2->data){

            temp->next = temp2;
            temp2 = temp2->next;

        }else{

            temp->next = temp1;
            temp1 = temp1 ->next;
        }

        temp = temp->next;
    }

    while(temp1 != nullptr){

        temp->next = temp1;

        temp1 = temp1->next;
        temp = temp->next;
    }

    while(temp2 != NULL){
        temp->next = temp2;

        temp2 = temp2 ->next;
        temp = temp->next;
    }

    return dummynode->next;
}

/*
    Everytime two lists are merged the time complexity is proportional to the sum of the number of nodes in them as we iterate over all nodes and merge according to the data values in them.

Assume the length of each list to be N1, N2, N3 and so on.

In the first iteration, when merging the first two lists (N1 and N2), the time complexity is N1 + N2.
In the second iteration, when merging the result of the first iteration with the third list (N3), the time complexity becomes (N1 + N2) + N3.
In the third iteration, merging the result of the second iteration with the fourth list (N4), the time complexity becomes ((N1 + N2) + N3) + N4.
This pattern continues until all K lists are merged.
The total time complexity can be expressed as:

T = (N1 + N2) + (N1 + N2 + N3) + .... + (N1 + N2 + N3 + .... + Nk)

For simplification let's assume the length of each linked list to be proportional to N,

T = N + 2N + 3N + 4N + 5N + .... + kN

T = N (1 + 2 + 3 + 4 + ... + k)

The sum of lengths of the lists can be calculated using the formula for the sum of the first N natural numbers:

T = N (k(k+1))/2

Hence, the time complexity is O( N*k(k+1)/2) ~ O(N*k^2)

Space Complexity: O(1) as no additional data structures or space is allocated for storing data, only a constant space for pointers to maintain for traversing the linked list and merging them in place.
*/

node* better(vector<node* > arr){
    node* head = arr[0];

    for(int i= 1  ; i< arr.size() ; i++){
        
        head = mergeTwoLists(head, arr[i]);
    }

    return head;
}

/*
Time Complexity: O(K log K) + O(N*K*(3*log K))where K is the number of linked lists and N is the number of nodes in each list.

O(K log K) as inserting an element into the priority queue takes log K time and is repeated K times for each list head.

Considering there are N nodes in each of the K linked lists, the overall number of nodes to be processed is N * K. For each of these N * K nodes:

Pop: Removing the smallest element (top of the priority queue) takes log K time.
Add: Adding the next element from the same list (when available) also takes log K time.
Access top: Accessing the top of the priority queue for extraction or comparison also takes log K time.
Hence, the total time complexity for the merging process across all nodes is ~ O(N * K * log K).

Space Complexity : O(K) where K is the number of linked lists. The main contributor to space usage is the priority queue which holds a node from each of these lists. Regardless of the number of nodes within each list, priority queue only holds a reference to one of its nodes at a time hence the space complexity is proportional to the number of input linked lists
*/
node* optimal(vector<node*> arr){

    // Priority queue to maintain
    // sorted order based on node values
    // Pairs store node value and pointer to the node
    priority_queue<pair<int, node*>,
        vector<pair<int, node*>>, greater<pair<int, node*>>> pq;

    for(int i =0 ; i< arr.size();i++){

        if(arr[i]){

            // Push the pair of head node data and
            // head node pointer into the priority queue
            pq.push({arr[i]->data,arr[i]});
        }

    }

        // Create a dummy node to build the merged list
        node* dummyNode = new node(-1);
        node* temp = dummyNode;

        //putting the elements of all linked list by their head 
        while(!pq.empty()){
        // Get the top element (minimum node value)
        // from the priority queue
        auto it = pq.top();
        pq.pop();
        
        // Check if the current
        // node has a next node
        if(it.second->next){
            // Push the next node
            // into the priority queue
            pq.push({it.second->next->data, it.second->next});
        }
        
        // Set the next pointer of the
        // current node in the merged list
        temp->next = it.second;
        temp = temp->next;
        }

        return dummyNode->next;
}



// Function to print the linked list
void printLinkedList(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->data << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}

int main() {
    // Create linked lists
    node* head1 = new node(2, new node(4, new node(6)));
    node* head2 = new node(1, new node(5));
    node* head3 = new node(1, new node(1, new node(3, new node(7))));
    node* head4 = new node(8);

    // Populate the lists vector
    vector<node*> lists = {head1, head2, head3, head4};
    
    cout << "Original Linked Lists:" << endl;
    for (int i = 0; i < lists.size(); ++i) {
        cout << "List " << i + 1 << ": ";
        printLinkedList(lists[i]);
    }

    // Merge the linked lists
    node* mergedList = optimal(lists);
    
    // Print the merged linked list
    cout << "Merged Linked List: ";
    printLinkedList(mergedList);

    return 0;
}

