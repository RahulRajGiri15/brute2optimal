//////brute approach 

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int>ans;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i] + nums[j] == target){
//                     ans.push_back(i);
//                     ans.push_back(j);
//                     break;
//                 }
//             }
//         }
//          return ans;
//     }
// };



////////////using two pointer 

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int i=0,j;
//         int sum = 0;
//         int n = nums.size();
//         vector<int>ans;
//         while(i<n){
//             j = i+1;
//             while(j<n){
//                 sum = nums[i]+nums[j];
//                 if(sum == target){
//                     ans.push_back(i);
//                     ans.push_back(j);
//                     break;
//                 }
//                 j++;
//             }
//             i++;
//         }  
//         return ans;
//     }
// };

/////////////-- using sorting ---- optimal bteats 100% 


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         int i=0;
//         int j = n-1;
//         vector<pair<int,int>>ans;
//         int sum =0;
//         for(int k=0;k<n;k++){
//             ans.push_back({nums[k],k});
//         }
//         sort(ans.begin(),ans.end());
//         while(i < j){
//             sum = ans[i].first+ans[j].first;
//             if(sum > target){
//                 j--;
//             }
//             if(sum < target){
//                 i++;
//             }
//             if(sum == target){
//                 return{ans[i].second,ans[j].second};
//             }
//         }
//         return {};
//     }
// };

/////t-o(2n + nlogn)-->nlogn
/////s-o(n)

/////////////hashing --- using map  --- better solution

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         map<int,int>mp;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             int rem = target - nums[i];
//             if(mp.count(rem)){
//                 return {mp[rem] , i};
//             }
//             mp[nums[i]] = i;
//         }
//         return {};
//     }
// };

// ////t-o(n)
// ////s-o(n)

///////////////


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n = nums.size();
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
        int x = target - nums[i];
        if(mp.find(x) != mp.end()){
            return { i , mp[x]};
        }
        else{
            mp[nums[i]] = i;
        }
    }
        return {};
    }
};