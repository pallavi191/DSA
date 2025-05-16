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
// 1 - null
// 2 - 200
// 3 - 300
// 4 - 400
// 5 - 500
Node* CreateLinkList(int (&arr)[5], int size, int index, Node* addr) {
    if(index == size) {
        return addr;
    }
    

    Node* temp = new Node(arr[index]);
    temp -> next = addr;
    return CreateLinkList(arr, 5, index + 1, temp);
}

int main() {
    Node* Head = NULL;
    
    int arr[5] = {1, 2, 3, 4, 5};
    
    // insert arr elements at the start of LL using recursion
    Head = CreateLinkList(arr, 5, 0, NULL);

    // print all elements of LL
    Node* temp = Head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
    // output - 5 4 3 2 1 
    
    return 0;
}