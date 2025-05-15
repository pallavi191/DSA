 
// insert start of the linked list
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};



int main() {
    Node* Head = NULL;
    
    int arr[5] = {1, 2 , 3, 4, 5};
    
    // insert arr elements at the start of LL
    for(int i = 0; i < 5; i++) {
        if(Head == NULL) {
            Head = new Node(arr[i]);
        } else {
            Node* temp = new Node(arr[i]);
            temp -> next = Head;
            Head = temp;
        }
    }

    // print all elements of LL
    Node* temp = Head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
    // output - 5 4 3 2 1
    return 0;
}