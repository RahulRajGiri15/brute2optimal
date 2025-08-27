// class Solution {
// public:
//     int m , n;
//     //int direction[4][2] = {{1,1},{1,-1},{-1,-1},{-1,1}};
//     vector<vector<int>>direction = {{1,1},{1,-1},{-1,-1},{-1,1}};

//     int solve(int i, int j, int d, vector<vector<int>>& grid,bool canturn, int val){
//         int ni = i + direction[d][0];
//         int nj = j + direction[d][1];

//         if(ni > m-1 || nj > n-1 || ni < 0 || nj < 0 || grid[ni][nj] != val){
//             return 0;
//         }
//         int length =0;
//         int keepmoving = 1 + solve(ni,nj,d,grid,canturn,val == 2? 0 : 2);
//             length = max(length,keepmoving);

//         if(canturn == true){
//             int turnandmove = 1 + solve(ni,nj,(d+1)%4,grid,false,val == 2 ? 0 : 2);
//             length = max(length,turnandmove);
//         }
//         return length;

//     }
//     int lenOfVDiagonal(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
        
//         int result = 0;

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 bool canturn = true;
//                 for(int d=0;d<=3;d++){
//                     if(grid[i][j] == 1){
//                         result = max(result, 1 + solve(i,j,d,grid,canturn,2));
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };



//////////////////memoization 

class Solution {
public:
    int m , n;
    //int direction[4][2] = {{1,1},{1,-1},{-1,-1},{-1,1}};
    vector<vector<int>>direction = {{1,1},{1,-1},{-1,-1},{-1,1}};
    
    int t[501][501][4][2];

    int solve(int i, int j, int d, vector<vector<int>>& grid,bool canturn, int val){
        int ni = i + direction[d][0];
        int nj = j + direction[d][1];

        if(ni > m-1 || nj > n-1 || ni < 0 || nj < 0 || grid[ni][nj] != val){
            return 0;
        }
        if(t[ni][nj][d][canturn] != -1){
            return t[ni][nj][d][canturn];
        }
        int length =0;
        int keepmoving = 1 + solve(ni,nj,d,grid,canturn,val == 2? 0 : 2);
            length = max(length,keepmoving);

        if(canturn == true){
            int turnandmove = 1 + solve(ni,nj,(d+1)%4,grid,false,val == 2 ? 0 : 2);
            length = max(length,turnandmove);
        }
        return t[ni][nj][d][canturn] = length;

    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        memset(t,-1,sizeof(t));

        int result = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool canturn = true;
                for(int d=0;d<=3;d++){
                    if(grid[i][j] == 1){
                        result = max(result, 1 + solve(i,j,d,grid,canturn,2));
                    }
                }
            }
        }
        return result;
    }
};