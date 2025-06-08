// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> st1; //right to left
        stack<TreeNode*> st2; //left to right
        vector<vector<int>> ans;
        st1.push(root);

        while(!st1.empty() || !st2.empty()) {
            vector<int> temp1;
            while(!st1.empty()) {
                TreeNode* temp = st1.top();
                st1.pop();
                temp1.push_back(temp -> val);
                if(temp -> left) st2.push(temp -> left);
                if(temp -> right) st2.push(temp -> right);
            }
            if(!temp1.empty()) ans.push_back(temp1);
            vector<int> temp2;
            while(!st2.empty()) {
                TreeNode* temp = st2.top();
                st2.pop();
                temp2.push_back(temp -> val);
                if(temp -> right) st1.push(temp -> right);
                if(temp -> left) st1.push(temp -> left);
            }
            if(!temp2.empty()) ans.push_back(temp2);
        }

        return ans;
    }
};
