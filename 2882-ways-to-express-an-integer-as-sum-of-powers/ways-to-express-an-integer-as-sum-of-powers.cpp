/////////recursion

// class Solution {
// public:
//      int M = 1e9 + 7;
//     int solve(int n , int num ,int x){

//         if(n == 0) return 1;
//         if(n < 0) return 0;
//         if(pow(num,x) > n) return 0;

//         int pick = solve(n-pow(num,x),num+1,x);
//         int notpick = solve(n,num+1,x);

//         return (pick+notpick)% M;
//     }

//     int numberOfWays(int n, int x) {
//         return solve(n,1,x);
//     }
// };

//////////memoization

class Solution {
public:
    int M = 1e9 + 7;
    int t[301][301];
    int solve(int n , int num ,int x){

        if(n == 0) return 1;
        if(n < 0) return 0;
        if(pow(num,x) > n) return 0;
        if(t[n][num] != -1) return t[n][num];
        int pick = solve(n-pow(num,x),num+1,x);
        int notpick = solve(n,num+1,x);

        return t[n][num] = (pick+notpick)%M;
    }

    int numberOfWays(int n, int x) {
        memset(t,-1,sizeof(t));
        return solve(n,1,x);
    }
};
