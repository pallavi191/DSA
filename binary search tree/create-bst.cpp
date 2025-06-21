// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


class TreeNode {
    public:
    TreeNode *left, *right;
    int data;
    
    TreeNode(int x) {
        left = right = NULL;
        data = x;
    }
};

TreeNode* insert(TreeNode* root, int target) {
    if(!root) {
        TreeNode *temp = new TreeNode(target);
        return temp;
    }
    
    if(target < root -> data)
    root -> left = insert(root -> left, target);
    else
    root -> right = insert(root -> right, target);
    
    return root;
}

void printTree(TreeNode* root) {
    if(!root)    
    return;
    
    cout << root -> data << " ";
    
    printTree(root -> left);
    printTree(root -> right);
}

int main() {
    // Write C++ code here
    int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
    int n = 10;
    TreeNode *root = NULL;

    for(int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    printTree(root);
    // output:
    // 6 3 2 1 5 17 11 14 18 20 

    return 0;
}
