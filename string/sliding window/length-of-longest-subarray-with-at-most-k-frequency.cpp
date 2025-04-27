class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int first = 0, second = 0, len = 0;

        while(second < nums.size()) {
            count[nums[second]]++;
            
            while(count[nums[second]] > k && first <= second) {
                count[nums[first]]--;
                first++;
            }

            len = max(len, second - first + 1);
            second++;
        }

        return len;
    }
};
