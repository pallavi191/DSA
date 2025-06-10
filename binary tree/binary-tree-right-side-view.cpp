// https://leetcode.com/problems/binary-tree-right-side-view/submissions/1660133162/

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
// with recursion
class Solution {
public:
    void rightView(TreeNode* root, int level, vector<int>& ans) {
        if(!root) return;

        if(ans.size() == level)
        ans.push_back(root -> val);

        rightView(root -> right, level + 1, ans);
        rightView(root -> left, level + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;

        rightView(root, 0, ans);

        return ans;
    }
};
