class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), start = 0, end = 0, sum = 0, count = INT_MAX;

        while(end < n) {
            sum += nums[end];

            while(sum >= target && start <= end) {
                sum -= nums[start];
                count = min(count, (end - start + 1));
                start++;
            }

            end++;
        }

        return count == INT_MAX ? 0 : count;
    }
};
