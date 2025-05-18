class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *curr = head, *temp = head, *prev = NULL;

        if(!head || head -> next == NULL)
        return head;

        int count = 0;

        while(temp) {
            count++;
            temp = temp -> next;
        }

        // if k is > count;
        k = k % count;
        
        if(k == 0)
        return head;

        count -= k;

        while(count--) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = NULL;
        ListNode* tail = curr;

        while(tail -> next != NULL) {
            tail = tail -> next;
        }

        tail -> next = head;

        head = curr;

        return head;
    }
};
