class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st(nums.begin(),nums.end());
        while(st.contains(original) == true){
            original = original * 2;
        }
        return original;
    }
};