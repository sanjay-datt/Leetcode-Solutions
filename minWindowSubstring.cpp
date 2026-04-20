class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        vector<int>freq(128,0);
        for(char ch : t){
            freq[ch] += 1;
        }
        int startIndex = -1;
        int minLen = INT_MAX;
        int l = 0;
        int r = 0;
        int required = t.size();

        while(r < s.size()){
            if(freq[s[r]] > 0){
                required--;
            }
            freq[s[r]]--;
            r++;
            while(required == 0){
                if(r-l < minLen){
                    minLen = r - l;
                    startIndex = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0){
                    required++;
                }
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIndex,minLen);
    }
};
