// implement queue using array
#include <iostream>
#include<vector>
using namespace std;
class Queue {
    int size, front, rear;
    int *arr;
    public:
    Queue(int n) {
        size = n;
        front = -1;
        rear = -1;
        arr = new int(size);
    }
    bool isEmpty() {
        return front == -1;    
    }
    
    int totalSize() {
        return size;
    }
    
    void push(int x) {
        // queue is empty
        if(isEmpty()) {
            front = 0;
            rear = 0;
            arr[front] = x;
            cout << "Inserted " << x << " in queue at " << rear << endl;
            // rear += 1;
        } else if(rear == size-1) { // queue is full
            cout << "Queue is overflow" << endl;
        } else {
            rear += 1;
            arr[rear] = x;
            cout << "Inserted " << x << " in queue at " << rear << endl;
        }
    }
    
    void pop() {
        // queue is empty
  
        if(rear == -1) {
            cout << "queue is underflow.." << endl;
        } else {
            cout << "deleted " << arr[front] << " from queue at " << front << endl;
            front += 1;
        }
    }
};


int main() {
    Queue Q1(5);
    Q1.push(1);   // Inserted 1 in queue at 0
    Q1.push(2);   // Inserted 2 in queue at 1
    Q1.push(3);   // Inserted 3 in queue at 2
    Q1.push(4);   // Inserted 4 in queue at 3
    Q1.push(5);   // Inserted 5 in queue at 4
    Q1.push(6);   // Queue is overflow
    Q1.pop();     // deleted 1 from queue at 0
    Q1.pop();     // deleted 2 from queue at 1
    Q1.push(6);   // Queue is overflow
    Q1.pop();     // deleted 3 from queue at 2
    Q1.push(6);   // Queue is overflow
    cout << Q1.isEmpty() << endl; // 0
    return 0;
}