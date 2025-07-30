class Solution {
public:
    int longlength(int idx,vector<int>& nums, int maxand , int currand){
        ////here we just have to find the subarray with maxm value longest
        int maxlen =0;
        int curlen =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == maxand){
                curlen++;
                maxlen = max(maxlen,curlen);
            }
            else{
                curlen=0;
            }
        }
        return maxlen;
    }
    int longestSubarray(vector<int>& nums) {
        ///bitwise AND ---> max bitwise AND is equal to max value present 
        int maxand = INT_MIN;
        for(int num : nums){
            if(num > maxand){
                maxand = num;
            }
        }
        int currand = 0;
        return longlength(0,nums,maxand,currand);
    }
};