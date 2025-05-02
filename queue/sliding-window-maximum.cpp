class Solution {
public:
    int findMax(queue<int> q) {
        int maxi = INT_MIN;
        while(!q.empty()) {
            if(maxi < q.front()) {
                maxi = q.front();
            }
            q.pop();
        }
        return maxi;
    }
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        queue<int> q;
        vector<int> maxWindow;
        for(int i = 0; i < k-1; i++) {
            q.push(arr[i]);
        }

        for(int i = k-1; i < arr.size(); i++) {
            q.push(arr[i]);
            int maxi = findMax(q);
            q.pop();

            maxWindow.push_back(maxi);
        }

        return maxWindow;
    }
};
