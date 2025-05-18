class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;

        ListNode* temp = head, *prev = NULL, *curr = head;

        while(temp) {
            count++;
            temp = temp -> next;
        }

        count -= n;
        // to delete 1st node
        if(count == 0) {
            head = curr -> next;
            delete curr;
            return head;
        }
        
        while(count--) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        delete curr;

        return head;
    }
};
