class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = 0;
        int sum = 0;
        int minLen=INT_MAX;
        while(high<n){
            if(sum<target){
                sum += nums[high++];
            }
            while(sum>=target){ 
                minLen = min(minLen, high-low);
                sum -= nums[low++];
            }
        }
        return minLen==INT_MAX?0: minLen;
    }
};
