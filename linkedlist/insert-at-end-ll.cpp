// insert end of the linked list
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
    Node* Tail = NULL;
    
    int arr[5] = {1, 2 , 3, 4, 5};
    
    // insert arr elements at the start of LL
    for(int i = 0; i < 5; i++) {
        if(Head == NULL) {
            Head = new Node(arr[i]);
            Tail = Head;
        } else {
            Node* temp = new Node(arr[i]);
            Tail -> next = temp;
            Tail = temp;
        }
    }

    // print all elements of LL
    Node* temp = Head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
    // output - 1 2 3 4 5 
    return 0;
} 
