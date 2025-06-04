// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> level;

        if(!root) return level;

        q.push(root);
        TreeNode* temp;

        while(!q.empty()) {
            // take q size - level by level
            int size = q.size();
            vector<int> currentLevel;
            
            for(int i = 0; i < size; i++) {
                temp = q.front();
                q.pop();
                currentLevel.push_back(temp -> val);
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }

            level.push_back(currentLevel);
        }

        return level;
    }
};
