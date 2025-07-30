///////Approach one

// class Solution {
// public:
//     int longlength(int idx,vector<int>& nums, int maxand){
//         ////here we just have to find the subarray with maxm value longest
//         int maxlen =0;
//         int curlen =0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i] == maxand){
//                 curlen++;
//                 maxlen = max(maxlen,curlen);
//             }
//             else{
//                 curlen=0;
//             }
//         }
//         return maxlen;
//     }
//     int longestSubarray(vector<int>& nums) {
//         ///bitwise AND ---> max bitwise AND is equal to max value present 
//         int maxand = INT_MIN;
//         for(int num : nums){
//             if(num > maxand){
//                 maxand = num;
//             }
//         }
//         return longlength(0,nums,maxand);
//     }
// };

/////t--o(n)
/////s--o(1)

///////Approach Two

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ///bitwise AND ---> max bitwise AND is equal to max value present 
        int maxand = INT_MIN;
        int maxlen = 0;
        int currstreak = 0;
        for(int num : nums){
            if(num > maxand){
                maxand = num;
                currstreak = 0;
                maxlen = 0;
            }
            if(num == maxand){
                currstreak++;
                maxlen = max(maxlen,currstreak);
            }
            else{
                currstreak = 0;
            }
        }
        return maxlen;
    }
};
