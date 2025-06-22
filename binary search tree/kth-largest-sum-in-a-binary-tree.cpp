// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            long long sum = 0;
            while(size--) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp -> val;
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            ans.push_back(sum);
        }

        sort(ans.rbegin(), ans.rend());

        if(ans.size() >= k)
        return ans[k-1];
        
        return -1;
        
    }
};
