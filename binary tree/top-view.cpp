// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    void findIndex(Node *root, int pos, int &l, int &r) {
        if(!root) return;
        
        l = min(l, pos);
        r = max(r, pos);
        
        findIndex(root -> left, pos - 1, l, r);
        findIndex(root -> right, pos + 1, l, r);
    }
    vector<int> topView(Node *root) {
        // code here
        int l = 0, r = 0;
        
        findIndex(root, 0, l, r);
        
        vector<int> ans(r - l + 1);
        vector<bool> indexing(r - l + 1, 0);
        
        queue<Node*> q;
        queue<int> iq;
        
        q.push(root);
        iq.push(-1 * l);
        
        while(!q.empty()) {
            Node *temp = q.front();
            int i = iq.front();
            q.pop();
            iq.pop();

            if(!indexing[i]) {
                indexing[i] = 1;
                ans[i] = temp -> data;
            }

            if(temp -> left) {
                iq.push(i - 1);
                q.push(temp -> left);
            }
            
            if(temp -> right) {
                iq.push(i + 1);
                q.push(temp -> right);
            }
        }
        
        return ans;
    }
};
