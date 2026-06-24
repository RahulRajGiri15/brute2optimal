class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        if (n == 1) return r - l + 1;

        const int MOD = 1e9 + 7;

        vector<long long> inc(r + 2, 0), dec(r + 2, 0);

        for (int x = l; x <= r; x++) {
            inc[x] = 1;
            dec[x] = 1;
        }

        for (int len = 2; len <= n; len++) {
            vector<long long> newInc(r + 2, 0), newDec(r + 2, 0);

            // Prefix sum for increasing transitions
            long long prefix = 0;
            for (int x = l; x <= r; x++) {
                newInc[x] = prefix;
                prefix = (prefix + dec[x]) % MOD;
            }

            // Suffix sum for decreasing transitions
            long long suffix = 0;
            for (int x = r; x >= l; x--) {
                newDec[x] = suffix;
                suffix = (suffix + inc[x]) % MOD;
            }

            inc = newInc;
            dec = newDec;
        }

        long long ans = 0;

        for (int x = l; x <= r; x++) {
            ans = (ans + inc[x] + dec[x]) % MOD;
        }

        return (int)ans;
    }
};