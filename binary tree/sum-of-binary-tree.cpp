// https://www.geeksforgeeks.org/problems/sum-of-binary-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions
// without sum variable
class Solution {
  public:
    int sumBT(Node* root) {
        // code here
        if(root == NULL) return 0;
        return (root -> data + sumBT(root -> left) + sumBT(root -> right));
    }
};

// with sum variable
class Solution {
  public:
    void sumOftree(Node* root, int& sum) {
        if(root == NULL) return;
        
        sum += root -> data;
        sumOftree(root -> left, sum);
        sumOftree(root -> right, sum);
    }
  
    int sumBT(Node* root) {
        // code here
        int sum = 0;
        sumOftree(root, sum);
        return sum;

    }
};
