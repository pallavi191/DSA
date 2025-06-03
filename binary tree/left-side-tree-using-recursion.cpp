#include <iostream>
using namespace std;

class Node {
    public:
    Node *left, *right;
    int val;
    Node(int x) {
        left = right = NULL;
        val = x;
    }
};

Node* createTree() {
    int x;
    cin >> x;


    if(x == -1)
    return NULL;

    Node *temp = new Node(x);

    cout << "Enter left child of " << temp -> val << endl;
    temp -> left = createTree();

    cout << "Enter right child of " << temp -> val << endl;
    temp -> right = createTree();
    
    return temp;
}

int main() {
    cout << "Enter root node of tree: " << endl;

    Node* root = createTree();

    return 0;
}
