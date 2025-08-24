// class Solution {
// public:
//     int findmax(vector<int>nums, int skip_id){
//         int count = 0;
//         int maxcount =0;
//         for(int i = 0; i<nums.size(); i++){

//             if(i == skip_id){
//                 continue;
//             }
//             if(nums[i] == 1){
//                 count++;
//                 maxcount = max(count,maxcount);
//             }
//             // if(nums[i] == 0){
//             //     count = 0;
//             // }
//             ///////
//             else{
//                 count = 0;
//             }
//         }
//         return maxcount;
//     }

//     int longestSubarray(vector<int>& nums) {
//         int result =0;
//         int cnt = 0;
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i] == 0){
//                 result = max(result,findmax(nums,i));
//             }
//             else{
//                 cnt++;
//             }
//         }
//         if(cnt == nums.size()){
//             return nums.size()-1;
//         }
//         return result;
//     }
// };

///////////////////////

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int zeroCount = 0;
        int longestWindow = 0;

        int i = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            zeroCount += (nums[j] == 0);
                          
            // Shrink the window until the zero counts come under the limit.
            while (zeroCount > 1) {
                zeroCount -= (nums[i] == 0);
                i++;
            }
              
            longestWindow = max(longestWindow, j - i);
        }

        return longestWindow;
    }
};