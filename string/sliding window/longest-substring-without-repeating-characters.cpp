class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int first = 0, second = 0, len = 0;

        vector<bool> characters(256, 0);

        while(second < s.size()) {
            // Repeating chars
            while(characters[s[second]]) {
                characters[s[first]] = 0;
                first++;
            }

            characters[s[second]] = 1;
            len = max(len, second - first + 1);
            second++;
        }

        return len;
    }
};
