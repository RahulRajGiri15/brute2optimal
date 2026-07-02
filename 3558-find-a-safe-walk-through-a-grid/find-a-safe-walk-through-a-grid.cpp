class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> maxHealth(n, vector<int>(m, -1));
        queue<pair<int, pair<int, int>>> q;

        int initialH = health - grid[0][0];
        if (initialH <= 0) return false;

        q.push({initialH, {0, 0}});
        maxHealth[0][0] = initialH;

        while (!q.empty()) {
            auto [currH, pos] = q.front();
            q.pop();

            int r = pos.first;
            int c = pos.second;

            if (r == n - 1 && c == m - 1) return true;

            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d];
                int nc = c + dy[d];

                if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

                int remH = currH - grid[nr][nc];

                if (remH <= 0) continue;
                if (remH <= maxHealth[nr][nc]) continue;

                maxHealth[nr][nc] = remH;
                q.push({remH, {nr, nc}});
            }
        }

        return false;
    }
};