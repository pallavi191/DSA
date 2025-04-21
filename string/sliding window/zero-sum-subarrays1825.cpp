class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        
        vector<int> prefix(arr.size(), 0);
        int total = 0, nos = 0;
        unordered_map<int, int> count;
        count[0] = 1;
        for(int i = 0; i < arr.size(); i++) {
            total += arr[i];
            nos += count[total];
            
            count[total]++;
        }
        
        return nos;
    }
};
