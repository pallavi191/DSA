class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int prefixSum = 0, total = 0;
        unordered_map<int, int> m;

        m[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            if(m.count(prefixSum - goal)) {
                total += m[prefixSum - goal];
            }

            m[prefixSum]++;
        }

        return total;
    }
};
