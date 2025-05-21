// https://www.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/0

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {

        // code here
        if(!head || !(head -> next))
        return head;
        
        Node* curr = head;
        
        while(curr && curr -> next) {
           if(curr -> data == curr -> next -> data) {
               Node *temp = curr -> next;
               curr -> next = temp -> next;
               delete temp;
           } else {
               curr = curr -> next;
           }
        }
        
        return head;
    }
};
