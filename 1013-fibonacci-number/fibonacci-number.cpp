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
/////t-o(2^n)---
/////s-o(1)---recusive stack - o(n)

/////////using momoization----dynamic programming --top to bottom 

class Solution {
public:
    int solve(int n,vector<int>&dp){

        if(n<=1) return n;
        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1,dp)+solve(n-2,dp);

    }
    int fib(int n) {

        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
/////t-o(n)
/////s-o(n)

////////////using bottom to top 

// class Solution {
// public:
//     int fib(int n){
//         if(n <=1) return n;  ////if n is 1, 0
//         /////////
//         vector<int>dp(n+1,-1);
//         dp[0] = 0;
//         dp[1] = 1;
//         for(int i=2;i<=n;i++){
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//         return dp[n];
//     }
// };
/////t-o(n)
/////s-o(n)

///////////

// class Solution {
// public:
//     int fib(int n){
//         if(n <= 1) return n; 
//         int a = 0; 
//         int b = 1;
//         int c ;
//         for(int i=1;i<n;i++){
//             c = a+b;
//             a = b;
//             b = c;
//         }
//         return c;
//     }
// };

////t-o(n)
////s-o(1)