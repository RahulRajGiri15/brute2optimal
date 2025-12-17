class Solution {
public:
    long long t[1001][501][3];

    // CASE:
    // 0 -> You have not bought anything and you have not short-sold anything.
    // 1 -> Normal transaction - you had bought, now you will sell normally
    // 2 -> Short selling transaction - you had sold, now you will buy back
    long long solve(int i, int k, int CASE, vector<int>& prices) {

        if (i == prices.size()) {
            if (CASE == 0)
                return 0;
            return INT_MIN; //an unfinished transaction is invalid.
        }

        if (t[i][k][CASE] != INT_MIN)
            return t[i][k][CASE];

        long long take = INT_MIN;
        long long dontTake;

        // Do nothing today
        dontTake = solve(i + 1, k, CASE, prices);

        // Take action
        if (k > 0) {
            if (CASE == 1) {
                // Sell today (complete normal transaction)
                take = prices[i] + solve(i + 1, k - 1, 0, prices);
            }
            else if (CASE == 2) {
                // Buy back today (complete short transaction)
                take = -prices[i] + solve(i + 1, k - 1, 0, prices);
            }
            else {
                // CASE == 0: start a transaction
                take = max(
                    -prices[i] + solve(i + 1, k, 1, prices), // buy (normal)
                     prices[i] + solve(i + 1, k, 2, prices)  // short sell
                );
            }
        }

        return t[i][k][CASE] = max(take, dontTake);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= k; j++)
                for (int l = 0; l < 3; l++)
                    t[i][j][l] = INT_MIN;

        return solve(0, k, 0, prices);
    }
};
