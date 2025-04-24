class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, n = s.size(), maxFreq = 0, left = 0, right = 0;
        unordered_map<char, int> count;

        while(right < n) {
            // Add character to frequency map
            count[s[right]]++;

            // Update most frequent char in window
            maxFreq = max(maxFreq, count[s[right]]);

            // If number of changes needed > k, shrink window from the left
            while(( right - left + 1 ) - maxFreq > k) {
                count[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);  // Update max length
            right++; // Expand window
        }

        return maxLen;
    }
};
