#include<bits/stdc++.h>

using namespace std;

class node{

    public:
    int data;
    node* next;

    node(int x){
        data=x;
        next = nullptr;
    }

    node(int x ,node* next1){
        data=x;
        next=next1;
    }

};
// Function to print the linked list
void printLinkedList(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


/*Time Complexity: O(2 * N) This is because we traverse the linked list twice: once to push the values onto the stack, and once to pop the values and compare with the linked list. Both traversals take O(2*N) ~ O(N) time.

Space Complexity: O(N) We use a stack to store the values of the linked list, and in the worst case, the stack will have all N values,  ie. storing the complete linked list. 
*/
bool brute(node* head){
    stack<int> st;

        node* temp= head;

        //stroing all elements to the stack
        while(temp!= nullptr){
            st.push(temp->data);
            temp=temp->next;
        }
        //reassinging temp to head for checking 
        temp= head;
        //checking if the traversing from front part values are same with stack 
        while(temp!= nullptr){
            int num = st.top();
            if(num==temp->data){
                temp=temp->next;
                st.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }

node* reverseLinkedList(node* head){
    // Check if the list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        
        // No change is needed;
        // return the current head
        return head; 
    }

    // Recursive step: Reverse the remaining 
    // part of the list and get the new head
    node* newHead = reverseLinkedList(head->next);

    // Store the next node in 'front'
    // to reverse the link
    node* front = head->next;

    // Update the 'next' pointer of 'front' to
    // point to the current head, effectively
    // reversing the link direction
    front->next = head;

    // Set the 'next' pointer of the
    // current head to 'null' to
    // break the original link
    head->next = NULL;

    // Return the new head obtained
    // from the recursion
    return newHead;
}

/*
Time Complexity: O (2* N) The algorithm traverses the linked list twice, dividing it into halves. During the first traversal, it reverses one-half of the list, and during the second traversal, it compares the elements of both halves. As each traversal covers N/2 elements, the time complexity is calculated as O(N/2 + N/2 + N/2 + N/2), which simplifies to O(2N), ultimately representing O(N). 

Space Complexity: O(1) The approach uses a constant amount of additional space regardless of the size of the input linked list. It doesn't allocate any new data structures that depend on the input size, resulting in a space complexity of O(1).
*/
bool isPalindrome(node* head){
    // Check if the linked list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        
         // It's a palindrome by definition
        return true; 
    }

    // Initialize two pointers, slow and fast,
    // to find the middle of the linked list
    node* slow = head;
    node* fast = head;

    // Traverse the linked list to find the
    // middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL) {
        
        // Move slow pointer one step at a time
        slow = slow->next;  
        
        // Move fast pointer two steps at a time
        fast = fast->next->next;  
    }
    //now the fast is at 2nd last node if ll is even  and fast is at last node if its a odd length ll
    //and slow is on middle

    // Reverse the second half of the
    // linked list starting from the middle
    node* newHead = reverseLinkedList(slow->next);

    // Pointer to the first half
    node* first = head;  
    
     // Pointer to the reversed second half
    node* second = newHead; 

     while (second != NULL) {
        
        // Compare data values of 
        // nodes from both halves
        
        // If values do not match,
        // the list is not a palindrome
        if (first->data != second->data) {
            
            // Reverse the second half 
            // back to its original state
            reverseLinkedList(newHead);  
            
            // Not a palindrome
            return false;
        }
        
         // Move the first pointer
        first = first->next; 
        
        // Move the second pointer
        second = second->next;  
    }
    
    // Reverse the second half
    // back to its original state
    reverseLinkedList(newHead);  
    
    // The linked list is a palindrome
    return true;  

}

int main() {
    // Create a linked list with
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    node* head = new node(1);
    head->next = new node(5);
    head->next->next = new node(2);
    head->next->next->next = new node(5);
    head->next->next->next->next = new node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
