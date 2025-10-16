class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        for(int num : nums){
            int rem = ((num % value)+value) % value;
            mp[rem]++;
        }
        int mex = 0;
        while(mp[(mex % value)] > 0){
            mp[(mex % value)]--;
            mex++;
        }
        return mex;
    }
};