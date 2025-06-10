// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        if(!root) return {};
        queue<Node*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front() -> data);
            int n = q.size();
            
            while(n--) {
                Node* temp = q.front();
                
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
                
                q.pop();
            }
        }
        
        return ans;
    }
};
