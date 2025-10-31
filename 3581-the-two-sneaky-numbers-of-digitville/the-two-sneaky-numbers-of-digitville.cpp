// class Solution {
// public:
//     vector<int> getSneakyNumbers(vector<int>& nums) {
//         sort(begin(nums) , end(nums));
//         int a =0 ,b =0;
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i] == nums[i+1]){
//                 b = a;
//                 a = nums[i];
//             }
//         }
//         return {a,b};
//     }
// };

///////t---o(n) + o(log n)
///////s---o(1)

//////////////////

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() -2; ////given numbers = 0 .... n-1
        int XOR = 0;  //a^b
        for(int num : nums){
            XOR ^= num;
        }
        for(int i=0;i<n;i++){
            XOR ^= i;
        }
        int trailzerocount = __builtin_ctz(XOR);
        int mask = (1 << trailzerocount);

        int G1 = 0;
        int G2 = 0;
        for(int num : nums){
            if(num & mask){
                G1 ^= num;
            }
            else{
                G2 ^= num;
            }
        }
        for(int num =0;num<n;num++){
            if(num & mask){
                G1 ^= num;
            }
            else{
                G2 ^= num;
            }
        }
        return {G1 , G2};
    }
};





//////////////////////////////

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