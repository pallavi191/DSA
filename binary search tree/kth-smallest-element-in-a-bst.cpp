// https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/1672506944/

class Solution {
public:
    void kthSmallestElement(TreeNode* root, int& k, int& mini) {
        if(!root) return;


        kthSmallestElement(root -> left, k, mini);
        k--;
        if(k == 0) {
            mini = root -> val;
            return;
        }
        kthSmallestElement(root -> right, k, mini);

    }
    int kthSmallest(TreeNode* root, int k) {
        int mini = -1;

        kthSmallestElement(root, k, mini);
        return mini;
    }
};
