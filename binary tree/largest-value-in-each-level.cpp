// https://www.geeksforgeeks.org/problems/largest-value-in-each-level/1?page=4&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

// User function Template for C++

class Solution {
  public:
    vector<int> largestValues(Node* root) {
        // code here
        queue<Node*> q;
        Node *temp;
        q.push(root);
        vector<int> ans;
        ans.push_back(root -> data);
        
        while(!q.empty()) {
            int size = q.size();

            int maxi = INT_MIN;
            for(int i = 0; i < size; i++) {
                temp = q.front();
                q.pop();
                if(temp -> left && temp -> right)
                maxi = max(max(temp -> left -> data, temp -> right -> data), maxi);
                else if(temp -> left)
                maxi = max(temp -> left -> data, maxi);
                else if(temp -> right)
                maxi = max(temp -> right -> data, maxi);
                
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            
            if(maxi != INT_MIN)
            ans.push_back(maxi);
            
        }
        
        return ans;
    }
    
};
