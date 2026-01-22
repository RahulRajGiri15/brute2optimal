// class Solution {
// public:
//     vector<int> getConcatenation(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>ans(2*n,0);
//         for(int i=0;i<n;i++){
//             ans[i] = ans[i+n] = nums[i];
//         }
//         return ans;
//     }
// };

/////////////////

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(nums.begin(),nums.end());
        ans.insert(ans.end(),nums.begin(),nums.end()); /// insert(pos,begin,end)
        return ans;
    }
};