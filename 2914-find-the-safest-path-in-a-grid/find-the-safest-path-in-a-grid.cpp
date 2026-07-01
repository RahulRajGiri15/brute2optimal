class Solution {
public:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    bool canReach(vector<vector<int>>& dist, int limit) {

        int n = dist.size();

        if (dist[0][0] < limit)
            return false;

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1)
                return true;

            for (auto &d : dirs) {

                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    !vis[nr][nc] &&
                    dist[nr][nc] >= limit) {

                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        queue<pair<int,int>> q;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Multi-Source BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for (auto &d : dirs) {

                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    dist[nr][nc] == INT_MAX) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        int low = 0;
        int high = 2 * n;
        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canReach(dist, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};