// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
stack<int>  pushSt;
stack<int>  popSt;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        pushSt.push(x);
    }
    
    int pop() {
        int top = 0;
        if(empty()) {
            return 0;
        } else {
            if(popSt.empty()) {
                while(!pushSt.empty()) {
                    popSt.push(pushSt.top());
                    pushSt.pop();
                }
            }
            top = popSt.top();
            popSt.pop();
        } 
        return top;
    }
    
    int peek() {
        int top = 0;
        if(!empty()) {
            if(popSt.empty()) {
                while(!pushSt.empty()) {
                    popSt.push(pushSt.top());
                    pushSt.pop();
                }
            }
            top = popSt.top();
        }

        return top;
    }
    
    bool empty() {
        return popSt.empty() && pushSt.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
