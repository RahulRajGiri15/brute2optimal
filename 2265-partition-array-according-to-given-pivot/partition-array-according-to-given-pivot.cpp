class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        for(auto x:nums)if(x<pivot)ans.push_back(x);
        for(auto x:nums)if(x==pivot)ans.push_back(x);
        for(auto x:nums)if(x >pivot)ans.push_back(x);
        return ans;
    }
};