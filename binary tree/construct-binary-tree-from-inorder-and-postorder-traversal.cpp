// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/1668780176/

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
    int findIndex(vector<int>& in, int start, int end, int target) {
        for(int i = start; i <= end; i++) {
            if(in[i] == target)
            return i;
        }
        return -1;
    }

    TreeNode* constructTree(vector<int>& in, vector<int>& post, int index, int start, int end) {
        if(start > end) return NULL;

        TreeNode* root = new TreeNode(post[index]);

        int pos = findIndex(in, start, end, post[index]);

        root -> right = constructTree(in, post, index - 1, pos + 1, end);
        root -> left = constructTree(in, post, index - (end - pos)- 1, start, pos - 1); 

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return constructTree(inorder, postorder, postorder.size() - 1, 0, inorder.size() - 1);
    }
};
