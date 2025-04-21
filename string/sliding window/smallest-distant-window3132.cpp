
class Solution {
  public:
    int findSubString(string& s) {
        // Your code goes here
        int first = 0, second = 0, len = s.size();
        int diff = 0;

        vector<int> characters(256, 0);
        
        for(int i = 0; i < s.size(); i++) {
            if(characters[s[i]] == 0)
            diff++;
            
            characters[s[i]]++;
        }
        
        for(int i = 0; i < 256; i++) {
            characters[i] = 0;
        }
        
        while(second < s.size()) {
            // diff exists
            while(diff && second < s.size()) {
                if(characters[s[second]] == 0)
                diff--;
                
                characters[s[second]]++;
                second++;
            }

            len = min(len, second - first);
            
            // till diff not become 1
            while(diff != 1) {
                len = min(len, second - first);
                characters[s[first]]--;
                
                if(characters[s[first]] == 0)
                diff++;
                
                first++;
            }
        }
        
        return len; 
        
    }
};
