class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int count = 1;
        int ptr1 = 0, ptr2 = 1;
        while(ptr2<n){
            if(nums[ptr1] == nums[ptr2]){
                ptr2++;
                continue;
            }
            swap(nums[++ptr1], nums[ptr2++]);
            count++;
        }
        return count;
    }
};
