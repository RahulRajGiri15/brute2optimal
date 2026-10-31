class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int mod = 1e9 + 7;
        vector<int> down(grid[0].size());  // ways to enter each cell from above
        down[0] = 1;
        for (auto& row : grid) {
            int right = 0;  // ways to enter the current cell from the left
            for (int j = 0; j < row.size(); j++) {
                if (row[j]) {  // a mirror swaps the flows
                    swap(right, down[j]);
                } else {  // an empty cell merges them
                    right = down[j] = (right + down[j]) % mod;
                }
            }
        }
        return down.back();
    }
};