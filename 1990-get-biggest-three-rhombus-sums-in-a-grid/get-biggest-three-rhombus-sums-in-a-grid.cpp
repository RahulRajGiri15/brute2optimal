class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> st;

        auto addToSet = [&](int val) {
            st.insert(val);
            if (st.size() > 3)
                st.erase(begin(st));
        };

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                addToSet(grid[r][c]);   //every cell is valid for rohmbus of side = 0

                for (int side = 1; r-side >= 0 && r+side < m && c-side >= 0 && c+side < n; side++) {

                    int sum = 0;

                    for (int k = 0; k < side; k++) {
                        sum += grid[r - side + k][c + k];   // top to right corner
                        sum += grid[r + k][c + side - k];   // right to bottom corner
                        sum += grid[r + side - k][c - k];   // bottom to left corner
                        sum += grid[r - k][c - side + k];   // left to top corner
                    }

                    addToSet(sum);
                }
            }
        }

        return vector<int>(rbegin(st), rend(st));
    }
};


