class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<int> dp(n + 1, 0);
        vector<int> pref(n + 1, 0);

        dp[0] = 1;
        pref[0] = 1;

        deque<int> minQ, maxQ;
        int i = 0, j = 0;

        while (j < n) {

            while (!maxQ.empty() && nums[j] > nums[maxQ.back()])
                maxQ.pop_back();
            maxQ.push_back(j);

            while (!minQ.empty() && nums[j] < nums[minQ.back()])
                minQ.pop_back();
            minQ.push_back(j);

            while (nums[maxQ.front()] - nums[minQ.front()] > k) {
                i++;
                if (!maxQ.empty() && maxQ.front() < i) maxQ.pop_front();
                if (!minQ.empty() && minQ.front() < i) minQ.pop_front();
            }

            dp[j + 1] = (pref[j] - (i > 0 ? pref[i - 1] : 0) + MOD) % MOD;
            pref[j + 1] = (pref[j] + dp[j + 1]) % MOD;

            j++;
        }

        return dp[n];
    }
};



