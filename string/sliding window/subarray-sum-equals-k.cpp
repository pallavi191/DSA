class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int PrefixSum = 0, total = 0;
        unordered_map<int, int> m;
        m[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            PrefixSum += nums[i];

            if(m.count(PrefixSum - k)) {
                total += m[PrefixSum - k];
                m[PrefixSum]++;
            } else
                 m[PrefixSum]++;
        }

        return total;

    }
};
