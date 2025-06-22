// https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

class Solution {
  public:
    void largest(Node *root, int &k, int &ans) {
        if(!root) return;
        
        largest(root -> right, k, ans);

        k--;
        if(k == 0) {
            ans = root -> data;
            return;
        }

        largest(root -> left, k, ans);
    }
        
    int kthLargest(Node *root, int k) {
        // Your code here
        int ans = -1;
        largest(root, k, ans);
        return ans;
    }
};
