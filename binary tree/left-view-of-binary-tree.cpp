// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
class Solution {
  public:
   
    void leftView(Node* root, int level, vector<int>& ans) {
        if(!root) return;
        
        if(ans.size() == level)
        ans.push_back(root -> data);
        
        leftView(root -> left, level + 1, ans);
        leftView(root -> right, level + 1, ans);
    }
    vector<int> leftView(Node *root) {
        // code here
        if(!root) return {};

        vector<int> ans;

        leftView(root, 0, ans);
        
        return ans;
    }
};
