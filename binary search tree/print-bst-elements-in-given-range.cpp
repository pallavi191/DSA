// https://www.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1?

class Solution {
  public:
  
    void printRangeNodes(Node *root, int low, int high, vector<int>& ans) {
        if(!root) return;
        
        if(root -> data > low && root -> data > high)
        printRangeNodes(root -> left, low, high, ans);
        else if(root -> data < low && root -> data < high)
        printRangeNodes(root -> right, low, high, ans);
        else {
            // inorder traverse - LNR
            printRangeNodes(root -> left, low, high, ans);
            ans.push_back(root -> data);
            printRangeNodes(root -> right, low, high, ans);
        }
    }
  
    vector<int> printNearNodes(Node *root, int low, int high) {
        // code here
        vector<int> ans;
        printRangeNodes(root, low, high, ans);
        return ans;
    }
};
