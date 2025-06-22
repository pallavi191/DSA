// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/1672401342/

class Solution {
public:
    TreeNode* constructBST(vector<int>& preorder, int& index, int& lower, int& upper) {
        if(index == preorder.size() || preorder[index] < lower || preorder[index] > upper)
        return NULL;

        TreeNode* root = new TreeNode(preorder[index++]);

        root -> left = constructBST(preorder, index, lower, root -> val);
        root -> right = constructBST(preorder, index, root -> val, upper);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0, lower = INT_MIN, upper = INT_MAX;
        return constructBST(preorder, index, lower, upper);
    }
};
