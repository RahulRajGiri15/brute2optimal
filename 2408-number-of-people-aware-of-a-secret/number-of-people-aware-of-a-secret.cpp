class Solution {
public:
    int MOD = 1e9 + 7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> t(n + 1, 0);
        // t[day] = number of people who learn the secret on "day"

        t[1] = 1;
        
        int count = 0; 

        for (int day = 2; day <= n; day++) {
            // people who become eligible to share on this day
            if (day - delay > 0) {
                count = (count + t[day - delay]) % MOD;
            }
            // people who forget on this day
            if (day - forget > 0) {
                count = (count - t[day - forget] + MOD) % MOD;
            }
            t[day] = count; //total number of people who will get to know today
        }


        // Count the people who still remember on day n
        int result = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0) {
                result = (result + t[day]) % MOD;
            }
        }

        return result;
    }
};