// class Solution {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
//         int i =0, j =0;
//         int n = nums.size();
//         int totalone = 0;
//         int count = 0;
//         int maxcount = INT_MIN;
//         for(int i=0;i<n;i++)
//         while(i<=j && j < n){
//             if(nums[i] == nums[j] && nums[i] == 1){
//                 count = j-i +1;
//                 maxcount = max(maxcount,count);
//                 j++;
//             }
//             else if(nums[i] != nums[j] ){
//                 i = j;
//                 j++;
//             }
//         }
//         return maxcount;
//     }
// };

/////////////////

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i =0, j =0;
        int n = nums.size();
        
        int count = 0;
        int maxcount = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                count++;
                maxcount = max(maxcount , count);
            }
            else{
                count = 0;
            }
        }
        return maxcount;
    }
};