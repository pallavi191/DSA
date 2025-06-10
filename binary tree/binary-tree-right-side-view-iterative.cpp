// https://leetcode.com/problems/binary-tree-right-side-view/submissions/1660130119/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*> q;
        vector<int> ans;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            ans.push_back(q.front() -> val);
            while(size--) {
                TreeNode* temp = q.front();
                q.pop();

                if(temp -> right) q.push(temp -> right);
                if(temp -> left) q.push(temp -> left);
            }
        }

        return ans;
    }
};
