// https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/1652742348/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        stack<TreeNode*> st;

        if(root) st.push(root);

        TreeNode* temp;

        while(!st.empty()) {
            temp = st.top();

            st.pop();

            if(temp -> right) st.push(temp -> right);

            if(temp -> left) st.push(temp -> left);

            preOrder.push_back(temp -> val);
        }

        return preOrder;
    }
};
