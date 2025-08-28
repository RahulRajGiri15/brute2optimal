class Solution {
public:
    int n;
    void sortdig(int r,int c, vector<vector<int>>& grid, bool asend){
        int i = r;
        int j = c;
        vector<int> vec;
        while(i< n && j< n){
            vec.push_back(grid[i][j]);
            i++;
            j++;
        }
        if(asend == false){
            sort(vec.begin(),vec.end(), greater<int>());
        }
        else if(asend == true){
            sort(vec.begin(),vec.end());
        }
            i = r; //// reassing values so that we can reinset in grid 
            j = c;
        for(int &num : vec){
            grid[i][j] = num;
            i++;
            j++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        //// things to do 
        //// bottom left triangle --- non- increasing order
        //// top right triangle -- non- decreasing order

        n = grid.size();

        /////for bottom-left matrix
        for(int row =0; row<n; row++){
            sortdig(row,0,grid, false);
        }
        /////for top-right matrix
        for(int col = 1; col<n; col++){
            sortdig(0,col,grid,true);
        }

        return grid;
    }
};