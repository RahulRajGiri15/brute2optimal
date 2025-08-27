class Solution {
public:
    int m , n;
    int direction[4][2] = {{1,1},{1,-1},{-1,-1},{-1,1}};

    int solve(int i, int j, int d, vector<vector<int>>& grid,bool canturn, int val){
        int ni = i + direction[d][0];
        int nj = j + direction[d][1];

        if(ni > m-1 || nj > n-1 || ni < 0 || nj < 0 || grid[ni][nj] != val){
            return 0;
        }
        int length =0;
        int keepmoving = 1 + solve(ni,nj,d,grid,canturn,val == 2? 0 : 2);
            length = max(length,keepmoving);

        if(canturn == true){
            length = max(length,1 + solve(ni,nj,(d+1)%4,grid,false,val == 2 ? 0 : 2));
        }
        return length;

    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int result = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool canturn = true;
                for(int d=0;d<=3;d++){
                    if(grid[i][j] == 1){
                        result = max(result,solve(i,j,d,grid,canturn,2)+1);
                    }
                }
            }
        }
        return result;
    }
};