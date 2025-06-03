// https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/1652749737/

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
    void traversePreorder(vector<int>& preOrder, TreeNode* x) {
        if(!x)
        return;

        // Node
        preOrder.push_back(x -> val);

        // Left
        traversePreorder(preOrder, x -> left);

        // Right
        traversePreorder(preOrder, x -> right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        traversePreorder(preOrder, root);
        return preOrder;
    }
};
