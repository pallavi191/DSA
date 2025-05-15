// https://leetcode.com/problems/time-needed-to-buy-tickets/submissions/1622178451/
// using queue - n^2 worst case
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> Q1;
        for(int i = 0; i < tickets.size(); i++)
        Q1.push(i);

        int time = 0;

        while(tickets[k]) {
            tickets[Q1.front()]--;
            time++;
           
            if(tickets[Q1.front()] != 0)
            Q1.push(Q1.front());

            Q1.pop();
        }
        return time;
    }
};

// traditional approach
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;

        for(int i = 0; i <= k; i++)
        time += min(tickets[k], tickets[i]);

        for(int i = k+1; i < tickets.size(); i++)
        time += min(tickets[k] - 1, tickets[i]);

        return time;
    }
};
