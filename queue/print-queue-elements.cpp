// implement queue using array
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    queue<int> Q1;
    vector<int> VQ;
    Q1.push(05);
    Q1.push(15);
    Q1.push(25);
    Q1.push(35);
    Q1.push(45);
    
    // print element and then add it to the back of the queue 
    int n = Q1.size();
    while(n--) {
        cout << Q1.front() << endl;
        Q1.push(Q1.front());
        Q1.pop();
    }
    
    // use vector to store pop element
    while(!Q1.empty()) {
        cout << Q1.front() << endl;
        VQ.push_back(Q1.front());
        Q1.pop();
    }
    for(int i = 0; i < VQ.size(); i++) {
        Q1.push(VQ[i]);
    }
    // print element then popped back
    while(!Q1.empty()) {
        cout << Q1.front() << endl;
        Q1.pop();
    }
    return 0;
}