class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(begin(nums) , end(nums));
        int a =0 ,b =0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                b = a;
                a = nums[i];
            }
        }
        return {a,b};
    }
};

///////t---o(n) + o(log n)
///////s---o(1)

//////////////////

// class Solution {
// public:
//     vector<int> getSneakyNumbers(vector<int>& nums) {
//         sort(begin(nums) , end(nums));
//         vector<int>ans;
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i] == nums[i+1]){
//                ans.push_back(nums[i+1]);
//             }
//         }
//         return ans;
//     }
// };

/////////

// class Solution {
// public:
//     vector<int> getSneakyNumbers(vector<int>& nums) {
//        unordered_map<int,int>mp;
//        for(int num : nums){
//             mp[num]++;
//        }
//        vector<int>ans;
//        for(auto &it : mp){
//         if(it.second == 2){
//             ans.push_back(it.first);
//         }
//        }
//          return ans;
//        }
// };