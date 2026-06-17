class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> len(s.size());
        long long cur = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') cur++;
            else if (ch == '*') {
                if (cur) cur--;
            }
            else if (ch == '#') {
                cur = min(2LL * cur, (long long)1e15);
            }

            len[i] = cur;
        }

        if (k >= cur) return '.';

        for (int i = s.size() - 1; i >= 0; i--) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') {
                if (len[i] - 1 == k) return ch;
            }
            else if (ch == '#') {
                long long prev = len[i] / 2;
                if (k >= prev) k -= prev;
            }
            else if (ch == '%') {
                k = len[i] - 1 - k;
            }
        }

        return '.';
    }
};