///////brtue force

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         unordered_set<int>st(nums.begin(),nums.end());
//         nums.clear();
//         for(auto &it : st){
//             nums.push_back(it);
//         }
//         sort(begin(nums),end(nums));
//         return nums.size();
//     }
// };

///////////////

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       vector<int>temp;
       int i=0;
       int j= i+1;
       int n = nums.size();
       temp.push_back(nums[i]);
       while(i < j && j< n){
            if(nums[i] != nums[j]){
                temp.push_back(nums[j]);
                i = j;
            }
            j++;
       }
       nums.clear();
       nums.assign(temp.begin(),temp.end());
       return nums.size();
    }
};