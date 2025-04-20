class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long sum = 0, count = 0, product = 0;
            int first = 0, second = 0, n = nums.size();
            while(second < n) {
                sum += nums[second];
                product = sum * (second - first + 1);
    
                while(product >= k && first <= second) {
                    sum -= nums[first];
                    first++;
                    product = sum * (second - first + 1);
                }
    
                count += (second - first + 1);
                second++;
            }
    
            return count;
            
        }
    };