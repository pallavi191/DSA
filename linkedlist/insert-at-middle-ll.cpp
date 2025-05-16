 // insert start of the linked list
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *CreateLinkList(int (&arr)[5], int size, int index, Node *addr) {
    if(index == size) {
        return addr;
    }
    

    Node *temp = new Node(arr[index]);
    temp -> next = addr;
    return CreateLinkList(arr, 5, index + 1, temp);
}

int main() {
    Node *Head = NULL;
    
    int arr[5] = {1, 2, 3, 4, 5};
    
    // insert arr elements at the start of LL using recursion
    Head = CreateLinkList(arr, 5, 0, NULL);

    // insert node at particular position
    Node *temp = Head;
    
    int x = 3; // on which position new value will be inserted
    int value = 30;
    
    x--;
    while(x--) {
        temp = temp -> next;
    }
    
    Node *temp2 = new Node(value);
    temp2 -> next = temp -> next;
    temp -> next = temp2;
    
    // print all elements of LL
    temp = Head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
    // output - 5 4 3 2 1 
    
    return 0;
}
