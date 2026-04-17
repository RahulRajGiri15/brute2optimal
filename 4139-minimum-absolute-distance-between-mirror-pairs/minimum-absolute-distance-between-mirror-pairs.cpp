class Solution {
public:
    int getReverse(int n) {
        int rev = 0;

        while(n > 0) {
            int rem = n%10;

            rev = rev*10 + rem;

            n /= 10;
        }

        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp; //reversed -> idx

        int result = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(mp.count(nums[i])) {
                result = min(result, i - mp[nums[i]]);
            }

            mp[getReverse(nums[i])] = i;
        }

        return result == INT_MAX ? -1 : result;
    }
};
