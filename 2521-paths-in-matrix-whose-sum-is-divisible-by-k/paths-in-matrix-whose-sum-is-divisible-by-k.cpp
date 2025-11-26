// class Solution {
// public:
//     int m , n;
//     int M = 1e9 + 7;
//     int solve(int i ,int j,int rem , int k, vector<vector<int>>& grid){
//         if(i >= m || j>= n) return 0;
//         if(i == m-1 && j == n-1){
//             return (rem + grid[i][j]) % k == 0 ? 1 : 0;
//         }
//         int right = solve(i,j+1,rem + grid[i][j],k,grid);
//         int down = solve(i+1,j, rem + grid[i][j],k,grid);

//         return (right + down) % M;
//     }
//     int numberOfPaths(vector<vector<int>>& grid, int k) {
//         m = grid.size();
//         n = grid[0].size();
//         int count = 0;
//         count = solve(0,0,0,k,grid);
//         return count ;
//     }
// };

///////////////


class Solution {
public:
    int m , n;
    int M = 1e9 + 7;
    vector<vector<vector<int>>>t;
    int solve(int i ,int j,int rem , int k, vector<vector<int>>& grid){
        if(i >= m || j>= n) return 0;
        if(i == m-1 && j == n-1){
            return (rem + grid[i][j]) % k == 0 ? 1 : 0;
        }
        if(t[i][j][rem] != -1){
            return t[i][j][rem];
        }
        int right = solve(i,j+1,(rem + grid[i][j])%k,k,grid);
        int down = solve(i+1,j, (rem + grid[i][j])%k,k,grid);

        return t[i][j][rem] = (right + down) % M;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        t.assign(m, vector<vector<int>>(n,vector<int>(k,-1)));
        int count = 0;
        count = solve(0,0,0,k,grid);
        return count ;
    }
};