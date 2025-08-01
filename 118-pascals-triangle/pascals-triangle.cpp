class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>>result;
        for(int i=1;i<=n;i++){
            vector<int>curres(i);
            curres[0] = 1;
            curres[i-1] = 1;
            for(int j=1;j<=i-2;j++){
                curres[j] = result[i-2][j-1] + result[i-2][j];
            }
            result.push_back(curres);
        }
        return result;
    }
};