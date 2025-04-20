class Solution {
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            int first = 0, second = 0, product = 1;
            int n = nums.size(), count = 0;
            while(second < n) {
                product *= nums[second];
    
                while(product >= k && first <= second) {
                    product /= nums[first];
                    first++;
                }
    
                count += second - first + 1;
                second++;
            }
    
            return count;
        }
    };