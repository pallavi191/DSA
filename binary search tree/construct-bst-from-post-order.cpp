// https://www.geeksforgeeks.org/problems/construct-bst-from-post-order/1

Node *constructBST(int post[], int& index, int lower, int upper) {
    if(index < 0 || post[index] < lower || post[index] > upper)
    return NULL;
    
    Node* root = new Node(post[index--]);
    
    root -> right = constructBST(post, index, root -> data, upper);
    root -> left = constructBST(post, index, lower, root -> data);
    
    return root;
}

Node *constructTree(int post[], int size) {
    // code here
    int upper = INT_MAX, lower = INT_MIN, index = size-1;
    return constructBST(post, index, lower, upper);
}
