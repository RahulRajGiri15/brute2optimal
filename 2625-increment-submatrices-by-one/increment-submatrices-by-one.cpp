class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n,0));
        for(auto &arr : queries){
            int strow = arr[0];
            int stcol = arr[1];
            int edrow = arr[2];
            int edcol = arr[3];
            for(int i=strow;i<=edrow;i++){
                for(int j=stcol;j<=edcol;j++){
                    res[i][j]++;
                }
            }
        }
        return res;
    }
};