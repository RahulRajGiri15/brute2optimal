class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prevsum = 0;
        int currsum = 0;
        int maxsum = INT_MIN;
        for(int i=0;i<nums.size();i++){
            currsum = max(nums[i],prevsum + nums[i]);
            maxsum = max(currsum , maxsum);
            prevsum = currsum;
        }
        return maxsum;
    }
};