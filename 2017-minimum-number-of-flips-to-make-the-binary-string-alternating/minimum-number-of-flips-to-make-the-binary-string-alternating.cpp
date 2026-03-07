class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;

        string s1, s2;

        for(int i = 0; i < 2*n; i++) {
            s1 += (i % 2 ? '0' : '1');
            s2 += (i % 2 ? '1' : '0');
        }

        int i = 0, j = 0;
        int result1 = 0, result2 = 0;
        int result = INT_MAX;

        while(j < 2*n) {

            // expand window
            if(s[j] != s1[j]) result1++;
            if(s[j] != s2[j]) result2++;

            // shrink if window exceeds n
            if(j - i + 1 > n) {
                if(s[i] != s1[i]) result1--;
                if(s[i] != s2[i]) result2--;
                i++;
            }

            // window size exactly n
            if(j - i + 1 == n)
                result = min({result, result1, result2});

            j++;
        }

        return result;
    }
};
