
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n < 0) return 0;
//         if(n == 0) return 1;
//         /////////
//         int x = climbStairs(n-1);
//         int y = climbStairs(n-2);

//         return x+y;

//     }
// };

//////////////

class Solution {
public:
    int solve(int n , vector<int>&dp){
        if(n < 0) return 0;
        if(n == 0) return 1;
        ////
        if(dp[n] != -1) return dp[n];
        int x = solve(n-1,dp);
        int y = solve(n-2,dp);

        return dp[n] = x+y;
    }
    int climbStairs(int n) {
        
        vector<int> dp(n+1,-1);

        return solve(n , dp);

    }
};