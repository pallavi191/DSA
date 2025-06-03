#include <iostream>
#include <queue>

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

int main() {
    queue<Node*> q;

    int first, second;

    Node* root = new Node(1);
    q.push(root);

    Node* temp = NULL;

    while(!q.empty()) {
        temp = q.front();
        cout << "Enter left child of " << temp -> val << endl;
        cin >> first;

        if(first > -1) {
            temp -> left = new Node(first);
            q.push(temp -> left);
        }

        cout << "Enter right child of " << temp -> val << endl;
        cin >> second;

        if(second > -1) {
            temp -> right = new Node(second);
            q.push(temp -> right);
        }

        q.pop();
    }
    return 0;
}
