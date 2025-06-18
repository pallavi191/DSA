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
    int findIndex(vector<int>& inorder, int start, int end, int target) {
        for(int i = start; i <= end; i++) {
            if(inorder[i] == target)
            return i;
        }

        return -1;
    }

    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int index, int inStart, int inEnd) {
        if(inStart > inEnd) return NULL;

        int pos = findIndex(inorder, inStart, inEnd, preorder[index]);

        TreeNode* root = new TreeNode(preorder[index]);
        root -> left = createTree(preorder, inorder, index + 1, inStart, pos - 1);
        root -> right = createTree(preorder, inorder, index+(pos - inStart)+1, pos + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(preorder, inorder, 0, 0, inorder.size()-1);
    }
};
