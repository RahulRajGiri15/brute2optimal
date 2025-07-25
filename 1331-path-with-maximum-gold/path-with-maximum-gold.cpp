// ///////////recursive solution 

class Solution {
public:
    int solve(vector<vector<int>>& grid,int i , int j){
        int m = grid.size();
        int n = grid[0].size();
        /////base condition 
        if(i < 0 || i>=m || j<0|| j>=n) return 0;
        if(grid[i][j] == 0) return 0;
        ////recursive condition
        //////it is not correct in cases -- as more blocks could have been visited
        int gold = grid[i][j];
        grid[i][j] = 0; //// marking the block

        int dir1 = solve(grid,i-1,j); ////up
        int dir2 = solve(grid,i,j+1); ////right
        int dir3 = solve(grid,i+1,j); ////down
        int dir4 = solve(grid,i,j-1); ////left

        grid[i][j] = gold; ////backtrack --- make grid same so it can be used in next operation

        return gold+ max({dir1,dir2,dir3,dir4});
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans , solve(grid,i,j));
            }
        }
        return ans;
    }
};

///////////////////In this we cant apply dp because there is no overlapping problem 

// class Solution {
// public:
//     int solve(vector<vector<int>>& grid,int i , int j,vector<vector<int>>& dp){
//         int m = grid.size();
//         int n = grid[0].size();
//         /////base condition 
//         if(i < 0 || i>=m || j<0|| j>=n) return 0;
//         if(grid[i][j] == 0) return 0;
//         ////recursive condition
//         //////it is not correct in cases -- as more blocks could have been visited
//         int gold = grid[i][j];
//         grid[i][j] = 0; //// marking the block

//         if(dp[i][j] != -1) return dp[i][j];
//         int dir1 = solve(grid,i-1,j,dp);////up
//         int dir2 = solve(grid,i,j+1,dp);////right
//         int dir3 = solve(grid,i+1,j,dp);////down
//         int dir4 = solve(grid,i,j-1,dp);////left

//         grid[i][j] = gold; ////backtrack --- make grid same so it can be used in next operation

//         return dp[i][j] = gold+ max({dir1,dir2,dir3,dir4});
//     }

//     int getMaximumGold(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
        
//         int ans =0;
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 ans = max(ans , solve(grid,i,j,dp));
//             }
//         }
//         return ans;
//     }
// };