class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st(nums.begin(), nums.end());
        vector<int>res(begin(st),end(st));
        sort(begin(res),end(res));
        nums = res;
        return nums.size();
    }
};