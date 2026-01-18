class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size(); //m
        int cols = grid[0].size(); // n
        //Row wise prefix sum
        vector<vector<int>> rowcumsum(rows,vector<int>(cols));
        for(int i =0;i<rows;i++){
            rowcumsum[i][0] = grid[i][0];
            for(int j =1;j<cols;j++){
                rowcumsum[i][j] = rowcumsum[i][j-1] + grid[i][j];
            }
        }
        //column wise prefix sum 
        vector<vector<int>> colcumsum(rows,vector<int>(cols));
        for(int j=0; j < cols; j++){
            colcumsum[0][j] = grid[0][j];
            for(int i=1;i<rows;i++){
                colcumsum[i][j] = colcumsum[i-1][j] + grid[i][j];
            }
        }

        ///try all possible square from each cell
        for(int side = min(rows,cols); side>=2; side--){

            for(int i=0; i+side - 1 < rows; i++){
                for(int j=0; j+side -1 < cols; j++){
                    int targetsum = rowcumsum[i][j+side-1] - (j>0?rowcumsum[i][j-1]:0);
                    bool allsame = true;
                    //check rows
                    for(int r = i+1;r<i+side;r++){
                        int rowsum = rowcumsum[r][j+side-1] - (j>0?rowcumsum[r][j-1]:0);
                        if(rowsum != targetsum){
                            allsame = false;
                            break;
                        }
                    }
                    if(!allsame){
                        continue;
                    }
                    //check column
                    for(int c=j;c<j+side;c++){
                        int colsum = colcumsum[i+side-1][c] -(i>0?colcumsum[i-1][c]:0);
                        if(colsum != targetsum){
                            allsame = false;
                            break;
                        }
                    }
                    if(!allsame){
                        continue;
                    }
                    //check for diag and antidiag
                    int diag = 0;
                    int antidiag = 0;
                    for(int k=0;k<side;k++){
                        diag += grid[i+k][j+k];
                        antidiag += grid[i+k][j+side-1-k];
                    }
                    if(diag == targetsum && antidiag == targetsum){
                        return side;
                    }
                }

            }
        }
        return 1;
    }
};