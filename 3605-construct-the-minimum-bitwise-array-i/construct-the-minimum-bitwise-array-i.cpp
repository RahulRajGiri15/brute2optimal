class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);
        for(int i = 0;i<nums.size();i++){
            if(nums[i] >= 2 ){
                for(int j = 1;j<=nums[i];j++){
                    if((j | (j+1)) == nums[i]){
                        ans[i] = j;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};