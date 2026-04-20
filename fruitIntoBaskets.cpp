class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();   
        map<int, int>mpp;
        int lar = -1;
        int low = 0;
        for(int high = 0; high<n; high++){
            mpp[fruits[high]]++;
            while(mpp.size()>2){
                mpp[fruits[low]]--;
                if(mpp[fruits[low]] == 0) mpp.erase(fruits[low]); 
                low++;
            }
            
            if(mpp.size() <= 2 ){
                int len = high-low+1;
                lar = max(lar, len);
            }
        }
        return lar;
    }
};
