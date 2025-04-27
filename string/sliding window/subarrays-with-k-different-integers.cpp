// using aleast k subarray
class Solution {
public:

    int subarraysWithKAtleast(vector<int>& nums, int k) {
        int first = 0, second = 0, count = 0, total = 0, n = nums.size();

        unordered_map<int, int> countInt;

        while(second < n) {
            countInt[nums[second]]++;

            if(countInt[nums[second]] == 1)
            count++;

            while(count >= k && first <= second) {
                if(count >= k)
                total += (n - second);

                countInt[nums[first]]--;

                if(countInt[nums[first]] == 0)
                count--;

                first++;
            }

            second++;
        }

        return total;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = subarraysWithKAtleast(nums, k) - subarraysWithKAtleast(nums, k + 1);
        return ans;
    }
};


// using atmost k subarray
class Solution {
public:

    int subarraysWithKAtmost(vector<int>& nums, int k) {
        int first = 0, second = 0, count = 0, total = 0, n = nums.size();

        unordered_map<int, int> countInt;

        while(second < n) {
            countInt[nums[second]]++;

            if(countInt[nums[second]] == 1)
            count++;

            while(count > k && first <= second) {
                countInt[nums[first]]--;

                if(countInt[nums[first]] == 0)
                count--;

                first++;
            }

            if(count <= k)
            total += (second - first + 1);

            second++;
        }

        return total;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = subarraysWithKAtmost(nums, k) - subarraysWithKAtmost(nums, k - 1);
        return ans;
    }
};
