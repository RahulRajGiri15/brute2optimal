// class Solution {
// public:
//     int countsubsets(int idx,vector<int>&nums,int maxor,int curror){
//         ////base case
//        if(idx == nums.size()){
//         if(curror == maxor) return 1; ///one subset found;
//         else return 0;
//        }
//         ////subsettaken nums[i]
//         int pick = countsubsets(idx+1,nums,maxor,curror | nums[idx]);
//         ////subset not taken nums[i]
//         int notpick = countsubsets(idx+1,nums,maxor,curror );
//         return pick+notpick;
//     }
//     int countMaxOrSubsets(vector<int>& nums) {
//         int maxor = 0;
//         for(int &num : nums){
//             maxor |= num;
//         }
//         int curror =0;
//         return countsubsets(0,nums,maxor,curror);
//     }
// };

//////////////lets memoization it 

class Solution {
public:
    int countsubsets(int idx,vector<int>&nums,int maxor,int curror,vector<vector<int>>& dp){
        ////base case
       if(idx == nums.size()){
        if(curror == maxor) return 1; ///one subset found;
        else return 0;
       }
       if(dp[idx][curror] != -1) return dp[idx][curror];
        ////subsettaken nums[i]
        int pick = countsubsets(idx+1,nums,maxor,curror | nums[idx],dp);
        ////subset not taken nums[i]
        int notpick = countsubsets(idx+1,nums,maxor,curror ,dp);
        return dp[idx][curror] = pick+notpick;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor = 0;
        for(int &num : nums){
            maxor |= num;
        }
        int curror =0;
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(maxor+1,-1));
        return countsubsets(0,nums,maxor,curror,dp);
    }
};