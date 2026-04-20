class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();   
        map<char, int>mpp;
        int lar = 0;
        int low = 0;
        for(int high = 0; high<n; high++){
            mpp[s[high]]++;
            int winSize = high-low+1;
            while(mpp.size()<winSize){
                mpp[s[low]]--;
                if(mpp[s[low]] == 0) mpp.erase(s[low]); 
                low++;
                winSize = high-low+1;
            }
            
            if(mpp.size() == winSize ){
                int len = high-low+1;
                lar = max(lar, len);
            }
        }
        return lar;
    }
};
