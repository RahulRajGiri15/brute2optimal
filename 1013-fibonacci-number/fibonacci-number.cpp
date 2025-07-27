/////////using recursion 

// class Solution {
// public:
//     int fib(int n) {
//         ////base case
//         if(n==0) return 0;
//         if(n==1) return 1;

//         ///////recursive code
//         return fib(n-1)+fib(n-2);
//     }
// };
/////t-
/////s-o(1)---recusive stack - o(n)

/////////using momoization----dynamic programming --top to bottom 

// class Solution {
// public:
//     int solve(int n,vector<int>&dp){

//         if(n<=1) return n;
//         if(dp[n] != -1) return dp[n];

//         return dp[n] = solve(n-1,dp)+solve(n-2,dp);

//     }
//     int fib(int n) {

//         vector<int> dp(n+1,-1);
//         return solve(n,dp);
//     }
// };

////////////using bottom to top 

class Solution {
public:
    int fib(int n){
        if(n <=1) return n;
        vector<int>dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};