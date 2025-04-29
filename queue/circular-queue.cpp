// implement circular queue using array

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
    bool isFull() {
        return (rear + 1) % size == front;    
    }
    int totalSize() {
        return size;
    }
    void startOfQueue() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front of the Queue is " << arr[front] << endl;
        }
    }
    void push(int x) {
        // queue is empty
        if(isEmpty()) {
            front = 0;
            rear = 0;
            arr[front] = x;
            cout << "Inserted " << x << " in queue at " << rear << endl;
            // rear += 1;
        } else if(isFull()) { // queue is full
            cout << "Queue is full.." << endl;
        } else {
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout << "Inserted " << x << " in queue at " << rear << endl;
        }
    }
    void pop() {
        // queue is empty
        if(isEmpty()) {
            cout << "queue is empty.." << endl;
        } else {
            if(rear == front) {
                cout << "deleted " << arr[front] << " from queue at " << front << endl;
                front = rear = -1;
            } else {
                cout << "deleted " << arr[front] << " from queue at " << front << endl;
                front = (front + 1) % size;
            }
        }
    }
};


int main() {
    Queue Q1(5);
    Q1.push(5);
    Q1.push(15);
    Q1.push(51); 
    Q1.push(125);
    Q1.push(511);
    Q1.pop();
    Q1.pop();
    Q1.push(511);

    return 0;
}