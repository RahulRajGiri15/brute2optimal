
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0;i<nums.size();i++){
            bool found = false;
            if(nums[i] == 2){
                ans.push_back(-1);
                continue;
            }
           for(int j=1;j<32;j++){
                if((nums[i] & (1 << j)) > 0){//if >0 than that bit is set(1 present)
                    continue;
                }
                /// bit not set 
                int prev = j -1;
                //make prev bit 0
                int x  = (nums[i]^(1<<(j-1)));
                ans.push_back(x);
                found = true;
                break;
           }
           if(found  == false){
            ans.push_back(-1);
           }
        }
        return ans;
    }
};