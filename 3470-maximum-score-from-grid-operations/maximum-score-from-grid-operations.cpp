class Solution {
public:
    typedef long long ll;
    int n;
    ll t[2][101][101];

    ll solve(bool prevTaken, int prevHeight, int col, vector<vector<int>>& grid, vector<vector<ll>>& colPrefSum) {
        
        if(col == n) {
            return 0;
        }
        
        ll result = 0;

        if(t[prevTaken][prevHeight][col] != -1) {
            return t[prevTaken][prevHeight][col];
        } 

        for(int height = 0; height <= n; height++) {
            ll prevColScore = 0;
            ll currColScore = 0;

            if(!prevTaken && col-1 >= 0 && height > prevHeight) {
                prevColScore += colPrefSum[height][col] - colPrefSum[prevHeight][col];
            }

            if(prevHeight > height) {
                currColScore += colPrefSum[prevHeight][col+1] - colPrefSum[height][col+1];
            }


            ll currColScoreTaken    = currColScore + prevColScore + solve(true, height, col+1, grid, colPrefSum);
            ll currColScoreNotTaken = prevColScore + solve(false, height, col+1, grid, colPrefSum);

            result = max({result, currColScoreTaken, currColScoreNotTaken});
        }

        return t[prevTaken][prevHeight][col] = result;

    }

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();

        memset(t, -1, sizeof(t));


        vector<vector<ll>> colPrefSum(n + 1, vector<ll>(n + 1, 0));

        for(int col = 1; col <= n; col++) {
            for(int row = 1; row <= n; row++) {
                colPrefSum[row][col] = colPrefSum[row-1][col] + grid[row-1][col-1];
            }
        }

        return solve(false, 0, 0, grid, colPrefSum);
    }
};

