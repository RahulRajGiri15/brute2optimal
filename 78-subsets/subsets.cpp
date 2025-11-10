//////this  is wrong this is a subset problem --- not a subarray problem 

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>>res;
//         res.push_back({});
//         int n = nums.size();
//         for(int i=0;i<n;i++){
         
//             for(int j=0;j<=i;j++){
//                 vector<int> temp; /// each time a new array for process
//                 for(int k=j;k<=i;k++){
//                     temp.push_back(nums[k]);
//                 }
//                 res.push_back(temp);
//                 ///or -- temp.erase();
//             }
//         }
//         return res;
//     }
// };

////////////////


class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int> &nums, int i ,vector<int>& temp){
        if(i >= nums.size()){
            res.push_back(temp);
            return;
        }
        ////backtracking
        temp.push_back(nums[i]);////take
        solve(nums,i+1,temp);
        temp.pop_back(); //// not take
        solve(nums, i+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums,0,temp);
        return res;
    }
};