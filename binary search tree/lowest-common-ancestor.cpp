// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/1672692328/

class Solution {
public:

    TreeNode* findPath(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if(root -> val < p -> val && root -> val < q -> val)
            return findPath(root -> right, p, q);
        else if(root -> val > p -> val && root -> val > q -> val)
            return findPath(root -> left, p, q);
        else
            return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findPath(root, p, q);
    }
};
