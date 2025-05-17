class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;
        while(temp != NULL) {
            ans.push_back(temp -> val);
            temp = temp -> next;
        }

        temp = head;

        for(int i = ans.size() - 1; i >=0; i--) {
            temp -> val = ans[i];
            temp = temp -> next;
        }

        return head;
    }
};
