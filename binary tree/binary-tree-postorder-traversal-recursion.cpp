// https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/1652785170/

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
    void traversePostorder(vector<int>& postOrder, TreeNode* root) {
        if(root == NULL) return;

        // Left
        traversePostorder(postOrder, root -> left);

        // Right
        traversePostorder(postOrder, root -> right);

        // Node
        postOrder.push_back(root -> val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> postOrder;

        traversePostorder(postOrder, root);
        return postOrder;

    }
};
