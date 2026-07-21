class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;
        for (char ch : s) {
            if (ch == '1') ones++;
        }

        int l = 0, r = n - 1;
        while (l < n && s[l] == '1') l++;
        while (r >= 0 && s[r] == '1') r--;

        if (l > r) return ones;

        vector<pair<int, char>> store;
        int len = 1;
        for (int i = l + 1; i <= r; i++) {
            if (s[i] == s[i - 1]) {
                len++;
            }
            else {
                store.push_back({len, s[i - 1]});
                len = 1;
            }
        }
        store.push_back({len, s[r]});

        int MaxRange = 0;
        for (int i = 0; i + 2 < store.size(); i += 2) {
            int range = store[i].first + store[i + 2].first;
            MaxRange = max(MaxRange, range);
        }
        return ones + MaxRange;
    }
};