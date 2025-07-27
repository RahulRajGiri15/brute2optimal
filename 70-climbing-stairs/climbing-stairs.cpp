////////recursive solution 

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
//////t-o(2^n)
/////s-o(1) --- recursive stack - o(n)

//////////////dp----memoization 

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

////t-o(n)
////s-o(n)

////////////bottom - up approach -- tabulataion method dp 

// class Solution {
// public:
//     int solve(int n , vector<int>&dp){
//         if(n < 0) return 0;
//         if(n <=2) return n;
//         dp[0] =0;
//         dp[1] =1;
//         dp[2] =2; /////---- can go with 2 ways {1,1} , {2}
        
//         //////
//         for(int i=3;i<=n;i++){
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//         return dp[n];
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n+1);
//         return solve(n , dp);

//     }
// };

/////t-o(n)
////s-o(n)

////////////more optimizing -- why don't we take 3 varibles instead 
///////// as here at a time we only require previous 2 values only 

// class Solution {
// public:
//     int solve(int n , vector<int>&dp){
//         if(n < 0) return 0;
//         if(n <=2) return n;

//         int a = 1;
//         int b = 2; /////---- can go with 2 ways {1,1} , {2}
//         int c = 3;
    
//         for(int i=3;i<=n;i++){
//             c = a + b;
//             a = b;
//             b = c;
//         }
//         return c;
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n+1);
//         return solve(n , dp);

//     }
// };

////t-o(n)
////s-o(1)