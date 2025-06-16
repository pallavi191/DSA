// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    void findIndex(Node *root, int pos, int &l, int &r) {
        if(!root) return;
        
        l = min(l, pos);
        r = max(r, pos);
        
        findIndex(root -> left, pos - 1, l, r);
        findIndex(root -> right, pos + 1, l, r);
    }
    
    
    vector<int> bottomView(Node *root) {
        // Your Code Here
        int l = 0, r = 0;
        findIndex(root, 0, l, r);
        
        queue<Node*> q;
        queue<int> iq;
        
        vector<int> ans(r - l + 1);
        
        q.push(root);
        iq.push(-1 * l);
        
        while(!q.empty()) {
            Node *temp = q.front();
            int i = iq.front();
            
            q.pop();
            iq.pop();
            
            ans[i] = temp -> data;

            if(temp -> left) {
                q.push(temp -> left);
                iq.push(i - 1);
            }
            
            if(temp -> right) {
                q.push(temp -> right);
                iq.push(i + 1);
            }
        }
        
        return ans;
    }
};
