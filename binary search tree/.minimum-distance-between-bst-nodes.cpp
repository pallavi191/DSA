// https://leetcode.com/problems/minimum-distance-between-bst-nodes/submissions/1672476308/

class Solution {
public:
    void diffInBST(TreeNode* root, int& prev, int& mini) {
        if(!root)
        return;

        diffInBST(root -> left, prev, mini);
        if(prev != INT_MIN)
        mini = min(root -> val - prev, mini);
        prev = root -> val;
        diffInBST(root -> right, prev, mini);
        
    }
    int minDiffInBST(TreeNode* root) {
        int prev = INT_MIN, mini = INT_MAX;
        diffInBST(root, prev, mini);
        
        return mini;
    }
};
