class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1000000007;
        const int MAX = 200;

        vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<int>> ndp(MAX + 1, vector<int>(MAX + 1, 0));

            for (int g1 = 0; g1 <= MAX; g1++) {
                for (int g2 = 0; g2 <= MAX; g2++) {
                    if (dp[g1][g2] == 0) continue;

                    long long ways = dp[g1][g2];

                    ndp[g1][g2] = (ndp[g1][g2] + ways) % MOD;

                    int ng1 = (g1 == 0) ? x : gcd(g1, x);
                    ndp[ng1][g2] = (ndp[ng1][g2] + ways) % MOD;

                    int ng2 = (g2 == 0) ? x : gcd(g2, x);
                    ndp[g1][ng2] = (ndp[g1][ng2] + ways) % MOD;
                }
            }

            dp = move(ndp);
        }

        long long ans = 0;

        for (int g = 1; g <= MAX; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return (int)ans;
    }
};