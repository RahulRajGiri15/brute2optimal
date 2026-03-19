class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>cumsumx(m , vector<int>(n,0));
        vector<vector<int>>cumsumy(m , vector<int>(n,0));
        int count = 0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                cumsumx[i][j] = (grid[i][j] == 'X');
                cumsumy[i][j] = (grid[i][j] == 'Y');

                if(i-1 >= 0){
                    cumsumx[i][j] += cumsumx[i-1][j];
                    cumsumy[i][j] += cumsumy[i-1][j];
                }

                if(j-1 >= 0){
                    cumsumx[i][j] += cumsumx[i][j-1];
                    cumsumy[i][j] += cumsumy[i][j-1];
                }

                if(i-1 >=0 && j-1 >= 0){
                    cumsumx[i][j] -= cumsumx[i-1][j-1];
                    cumsumy[i][j] -= cumsumy[i-1][j-1];
                }
                
                if(cumsumx[i][j] == cumsumy[i][j] && cumsumx[i][j] > 0){
                    count++;
                }

                
            }
        }
        return count;
    }
};