// https://www.geeksforgeeks.org/problems/height-of-binary-tree/1?page=1&difficulty[]=0&category[]=Tree&sortBy=submissions

class Solution {
  public:
    int height(Node* node) {
        // code here
        if(node == NULL) return -1;
        
        return 1 + max(height(node->left), height(node->right));

    }
};
