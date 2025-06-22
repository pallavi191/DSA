// https://www.geeksforgeeks.org/problems/sum-of-k-smallest-elements-in-bst3029/1

void sumOfBST(Node* root, int &k, int &sum, int &index) {
    if(!root)
    return;
    
    sumOfBST(root -> left, k, sum,index);
    
    if(k > 0) {
        sum += root -> data; 
        k--;
        
    }
    
    sumOfBST(root -> right, k, sum, index);
}
int sum(Node* root, int k) {

    // Your code here
    int sum = 0, index = k;
    sumOfBST(root, k, sum, index);
    return sum;
}
