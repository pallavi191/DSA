 
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

Node* CreateLinkList(int (&arr)[5], int size, int index) {
    if(index == size) {
        return NULL;
    }
    

    Node* temp = new Node(arr[index]);
    temp -> next = CreateLinkList(arr, 5, index + 1);
    return temp;
}

int main() {
    Node* Head = NULL;
    
    int arr[5] = {1, 2 , 3, 4, 5};
    
    // insert arr elements at the start of LL using recursion
    Head = CreateLinkList(arr, 5, 0);

    // print all elements of LL
    Node* temp = Head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
    // output - 1 2 3 4 5 
    
    return 0;
}