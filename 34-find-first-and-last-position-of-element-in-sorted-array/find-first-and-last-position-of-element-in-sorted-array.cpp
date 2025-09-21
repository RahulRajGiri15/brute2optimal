class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target){
                result.push_back(i);
            }
        }
        if(result.size() == 0){
            return {-1 , -1};
        }
        if(result.size() == 1){
            result.push_back(result[0]);
        }
        if(result.size() > 2){
            int a = result[0];
            int e = result[result.size() -1];
            result.clear();
            result.push_back(a);
            result.push_back(e);

        }
        return result;
    }
};