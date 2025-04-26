class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size() > s.size()) return "";

        int first = 0, second = 0, ans = INT_MAX, index = -1, diff = t.size();

        unordered_map<char, int> count;

        for(int i = 0; i < t.size(); i++)
        count[t[i]]++;

        // traverse s string to find substring
        while(second < s.size()) {
            // decrease count from count map to track that char is visited
            count[s[second]]--;

            // decrese diff if value is positive bcs we have only characters in t
            if(count[s[second]] >= 0)
            diff--;

            // if diff is 0 then we have got substring so lets try to decrease substring length
            while(!diff && first <= second) {
                // if ans is > then we have find less substring
                if(ans > second - first + 1) {
                    index = first; // store start of the substring
                    ans = second - first + 1; // store length of the substring
                }

                // decrease character
                count[s[first]]++;

                if(count[s[first]] > 0)
                diff++;

                first++;
            }

            second++;
        }

        if(index == -1)
        return "";

        string result = "";

        for(int i = index; i < index + ans; i++)
        result += s[i];

        return result;
    }
};
