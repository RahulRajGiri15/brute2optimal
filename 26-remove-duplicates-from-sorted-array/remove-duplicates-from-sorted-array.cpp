// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         unordered_set<int>st(nums.begin(), nums.end());
//         vector<int>res(begin(st),end(st));
//         sort(begin(res),end(res));
//         nums = res;
//         return nums.size();
//     }
// };

///////////////two pointer approach

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i =0 , j = 1;
        vector<int>res;
        res.push_back(nums[0]);
        while(i<= j && j < n){

           if(nums[i] == nums[j]){
            j++;
           }
           else if(nums[i] != nums[j]){
            i = j;
            res.push_back(nums[i]);
            j++;
           }
        }
        nums= res;
        return nums.size();
    }
};