class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());

        int first = 0, second = 0, count = 0, n = nums.size();

        long long total = 0;

        while(second < n) {
            if(nums[second] == maxElement)
            count++;

            while(count >= k && first <= second) {
                if(count >= k)
                total += (n - second);

                if(nums[first] == maxElement)
                count--;
                
                first++;
            }

            second++;
        }
        return total;
    }
};
