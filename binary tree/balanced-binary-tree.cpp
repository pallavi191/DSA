// https://leetcode.com/problems/balanced-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int isBalancedTree(TreeNode* root, bool& isValid) {
        if(!root) return 0;
        int L = isBalancedTree(root -> left, isValid);
        int R = isBalancedTree(root -> right, isValid);

        if(abs(L - R) > 1) isValid = false;

        return 1 + max(L, R);
    }
    bool isBalanced(TreeNode* root) {
        bool isValid = true;
        isBalancedTree(root, isValid);
        return isValid;
    }
};
