class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        nums.clear();
        for(auto &it : st){
            nums.push_back(it);
        }
        sort(begin(nums),end(nums));
        return nums.size();
    }
};