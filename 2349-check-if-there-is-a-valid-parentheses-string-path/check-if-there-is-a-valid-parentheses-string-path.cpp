// class Solution {
// public:
//     int n , m;
//     bool isval(int i , int j , vector<vector<char>> & grid,int balance){
//         if(i < 0 || j < 0 || i >= n || j >= m){
//             return false;
//         }
//         if(grid[i][j] == '('){
//             balance++;
//         }
//         else{
//             balance-=1;
//         }
//         if(balance < 0) return false;
//         if(i == n-1 && j == m-1){
//             return balance == 0;
//         }
//         bool right = isval(i, j+1,grid,balance);
//         bool down  = isval(i+1 , j , grid,balance);
//         return down || right;
 
//     }

//     bool hasValidPath(vector<vector<char>>& grid) {
//         n = grid.size();
//         m = grid[0].size();
//         if(grid[0][0] == ')'){
//             return false;
//         }
//         if(grid[n-1][m-1] == '('){
//             return false;
//         }
//         return isval(0,0,grid,0);
//     }
// };



class Solution {
public:
    int n , m;
    vector<vector<vector<int>>>dp;
    bool isval(int i , int j , vector<vector<char>> & grid,int balance){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return false;
        }
        if(grid[i][j] == '('){
            balance++;
        }
        else{
            balance-=1;
        }
        if(balance < 0) return false;
        if(i == n-1 && j == m-1){
            return balance == 0;
        }
        if(dp[i][j][balance] != -1){
            return dp[i][j][balance];
        }
        bool right = isval(i, j+1,grid,balance);
        bool down  = isval(i+1 , j , grid,balance);
        return dp[i][j][balance] = down || right;
 
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(n+m,-1)));

    
        if(grid[0][0] == ')'){
            return false;
        }
        if(grid[n-1][m-1] == '('){
            return false;
        }
        return isval(0,0,grid,0);
    }
};