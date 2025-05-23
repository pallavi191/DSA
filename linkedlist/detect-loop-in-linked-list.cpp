class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        if (head == NULL) {
            return false;  // Early return for empty list
        }

        Node *fast = head;
        Node *slow = head;

        while(fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)
            return 1;
        }
        
        return 0;
    }
};
