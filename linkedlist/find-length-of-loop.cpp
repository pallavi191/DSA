class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node *fast = head;
        Node *slow = head;
        
        while(fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
            
            if(slow == fast)
            break;
        }

        if(fast == NULL || fast -> next == NULL) {
            return 0;
        }
        
        int count = 1;
        slow = slow -> next;
        
        while(fast != slow) {
            count++;
            slow = slow -> next;
        }
        
        return count;
    }
};
