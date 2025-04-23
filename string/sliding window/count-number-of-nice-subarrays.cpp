class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddCount = 0, total = 0;

        unordered_map<int, int> m;

        m[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 1)
            oddCount++;

            if(m.count(oddCount - k)) 
            total += m[oddCount - k];

            m[oddCount]++;
        }

        return total;
    }
};
