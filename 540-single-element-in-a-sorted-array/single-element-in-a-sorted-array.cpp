// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         unordered_map<int ,int> mp;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;
//         }
//         for(auto &it : mp){
//             if(it.second == 1){
//                 return it.first;
//             }
//         }
//         return -1;
//     }
// };

/////////////////

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int i=0;
        while(i < n-1){
            if(nums[i] != nums[i+1]){
                break;
            }
            i = i+2;
        }
        return nums[i];
    }
};