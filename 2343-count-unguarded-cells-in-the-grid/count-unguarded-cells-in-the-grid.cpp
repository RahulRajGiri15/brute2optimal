/////////////brute soltuion --- using loop

// class Solution {
// public:
//     void markgaurded(int row, int col , vector<vector<int>> &grid){
//         /////here we have to check in all possible direction 
//         int m = grid.size();
//         int n = grid[0].size();
//         ///up -- col constant
//         for(int i=row-1; i>=0; i--){
//             if(grid[i][col] == 2 || grid[i][col] == 3){
//                 break;
//             }
//             grid[i][col] = 1;
//         }

//         //////Down --- col constant
//         for(int i=row+1; i<m; i++){
//             if(grid[i][col] == 2 || grid[i][col] == 3){
//                 break;
//             }
//             grid[i][col] = 1;
//         }

//         ////////left -- row constant
//         for(int i=col-1; i>=0; i--){
//             if(grid[row][i] == 2 || grid[row][i] == 3){
//                 break;
//             }
//             grid[row][i] = 1;
//         }
//         ////////right -- row constant
//           for(int i=col+1; i<n; i++){
//             if(grid[row][i] == 2 || grid[row][i] == 3){
//                 break;
//             }
//             grid[row][i] = 1;
//         }
//     }
//     int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
//         vector<vector<int>>grid(m , vector<int>(n,0));
//         for(vector<int> &vec : guards){
//             int i = vec[0];
//             int j = vec[1];
//             grid[i][j] = 2; /// gaurd
//         }
//         for(auto &vec : walls){
//             int i = vec[0];
//             int j = vec[1];
//             grid[i][j] = 3; //// walls
//         }
//         for(auto &gaurd : guards){
//             int i = gaurd[0];
//             int j = gaurd[1];
//             markgaurded(i,j,grid);
//         }
//         int count =0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j] == 0){ ////ungaurded section --- is marked 0 at start
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };


///////////////////////recursive solution 

class Solution {
public:
    void markgrid(int row, int col ,int rdir , int cdir ,vector<vector<int>> &grid){
        /////here we have to check in all possible direction 
        int m = grid.size();
        int n = grid[0].size();
        
        if(row <0 || row>=m || col <0|| col>=n|| grid[row][col] ==2 || grid[row][col] == 3){
            return;
        }
        grid[row][col] = 1; ///gird at row , col to be marked

        markgrid(row + rdir , col + cdir , rdir , cdir , grid);
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>>grid(m , vector<int>(n,0));
        for(vector<int> &vec : guards){
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 2; /// gaurd
        }
        for(auto &vec : walls){
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 3; //// walls
        }
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}}; /// all possible directions
        for(auto &g : guards){
           for(auto &d : dirs){
                markgrid(g[0] + d.first, g[1]+d.second, d.first,d.second,grid);
           }
        }
        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){ ////ungaurded section --- is marked 0 at start
                    count++;
                }
            }
        }
        return count;
    }
};