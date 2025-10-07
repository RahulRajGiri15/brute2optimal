///////////recursion solution

// class Solution {
// public:
//     int solve(vector<int>&nums, int i,vector<int>&dp){
//             if(i >= nums.size()) return 0;

//             //////here thief has option to pick and not pick
//             int pick = nums[i] + solve(nums,i+2);
//             int not_pick = solve(nums,i+1);
            
//             return max(pick , not_pick);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         return solve(nums,0,dp);
//     }
// };

////t-o(2^n)
////s-o(1)--- recursion stack --- (n)

////////////Dp -- using Memoization 

// class Solution {
// public:
//     int solve(vector<int>&nums, int i,vector<int>&dp){
//             if(i >= nums.size()) return 0;
            
//             if(dp[i] != -1) return dp[i];
//             int pick = nums[i] + solve(nums,i+2,dp);
//             int not_pick = solve(nums,i+1,dp);
            
//             return dp[i]= max(pick , not_pick);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
        
//         vector<int>dp(n+1,-1);
//         return solve(nums,0,dp);
//     }
// };
/////t-o(n)
/////s-o(n)

//////////////dp - another method using memoization 

// class Solution {
// public:
//     int t[101];
//     int solve(vector<int>&nums, int i,int n){
//             if(i >= n) return 0;
            
//             if(t[i] != -1) return t[i];
//             int pick = nums[i] + solve(nums,i+2,n);
//             int not_pick = solve(nums,i+1,n);
            
//             return t[i]= max(pick , not_pick);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
        
//         memset(t,-1,sizeof(t));
//         return solve(nums,0,n);
//     }
// };

////t-o(n)
////s-o(n)
//////////////using tabulation method --- bottom up approach

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>t(n+1,0);
//         ////t[i] == maximum money stolen till i house
//         t[0] = 0;
//         t[1] = nums[0];
//         if(n<0) return 0;
//         if(n<= 1) return t[n];
//         for(int i=2;i<=n;i++){
//             int steal = nums[i-1]+t[i-2];
//             int not_steal = t[i-1];
//             t[i] = max(steal,not_steal);
//         }
//         return t[n];
//     }
// };

/////t-o(n)
////s-o(n)


/////////////////////////////////


// class Solution {
// public:
//     int solve(vector<int>& nums,int i){
//         if(i > nums.size() - 1){
//             return 0;
//         }

//         int steal = nums[i] + solve(nums,i+2);
//         int skip = solve(nums,i+1);

//         return max(steal,skip);
        
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         return solve(nums,0);
//     }
// };

////////////////////////////

// class Solution {
// public:
//     int solve(vector<int>& nums,int i,vector<int>&dp){
//         if(i > nums.size() - 1){
//             return 0;
//         }
//         if(dp[i] != -1)return dp[i];
//         int steal = nums[i] + solve(nums,i+2,dp);
//         int skip = solve(nums,i+1,dp);

//         return dp[i] = max(steal,skip);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>dp(n,-1);
//         return solve(nums,0,dp);
//     }
// };

////////////////////

// class Solution {
// public:
//     int t[101];
//     int solve(vector<int>& nums,int i){
//         if(i > nums.size() - 1){
//             return 0;
//         }
//         if(t[i] != -1) return t[i];
//         int steal = nums[i] + solve(nums,i+2);
//         int skip = solve(nums,i+1);

//         return t[i] = max(steal,skip);
        
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         memset(t, -1 ,sizeof(t));
//         return solve(nums,0);
//     }
// };



///////////////

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>t(n+1,0); /////maxm money by robbing till i housese
        t[0] =0;
        t[1] = nums[0];
        for(int i=2;i<=n;i++){
            int steal = nums[i-1] + t[i-2] ;
            int skip  = t[i-1];
            t[i] = max(steal,skip);
        }
        return t[n];
    }
};