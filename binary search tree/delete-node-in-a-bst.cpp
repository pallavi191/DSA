// https://leetcode.com/problems/delete-node-in-a-bst/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root -> val > key) {
            root -> left = deleteNode(root -> left, key);
            return root;
        }
        else if(root -> val < key) {
            root -> right = deleteNode(root -> right, key);
            return root;
        } else {
            // root has no children
            if(!root -> left && !root -> right) {
                delete root;
                return NULL;
            }
            // root has left children
            else if(root -> left && !root -> right) {
                TreeNode* temp = root -> left;  
                delete root;
                return temp;
            }
            // root has right children
            else if(!root -> left && root -> right) {
                TreeNode* temp = root -> right;  
                delete root;
                return temp;
            }
            // root has both children
            else {
                TreeNode* child = root -> left;
                TreeNode* parent = root;

                while(child -> right) {
                    parent = child;
                    child = child -> right;
                }
                
                if(parent == root) {
                    child -> right = root -> right;
                    delete root;
                    return child;
                }
                else {
                    parent -> right = child -> left;
                    child -> left = root -> left;
                    child -> right = root -> right;
                    delete root;
                    return child;
                }
            }
        }

        return root;
    }
};
