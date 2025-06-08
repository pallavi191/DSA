// https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        stack<Node*> st1; //left to right
        stack<Node*> st2; //right to left
        
        vector<int> ans;

        st1.push(root);
        
        while(!st1.empty() || !st2.empty()) {
            while(!st1.empty()) {
                Node *temp = st1.top();
                st1.pop();
                if(temp -> right) st2.push(temp -> right);
                if(temp -> left) st2.push(temp -> left);
                ans.push_back(temp -> data);
            }
            
            while(!st2.empty()) {
                Node *temp = st2.top();
                st2.pop();
                if(temp -> left) st1.push(temp -> left);
                if(temp -> right) st1.push(temp -> right);
                ans.push_back(temp -> data);
            }
        }
        return ans;
    }
};
