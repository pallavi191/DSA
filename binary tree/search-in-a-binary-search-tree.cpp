// https://leetcode.com/problems/search-in-a-binary-search-tree/
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
    TreeNode* findNode(TreeNode* root, int target) {
        if(!root) return NULL;

        if(root -> val == target)
        return root;

        if(root -> val < target)
        return findNode(root -> right, target);
        else
        return findNode(root -> left, target);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return findNode(root, val);
    }
};
