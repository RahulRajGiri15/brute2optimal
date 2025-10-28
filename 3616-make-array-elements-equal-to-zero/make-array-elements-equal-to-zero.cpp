class Solution {
public:
    int countValidSelections(vector<int>& nums) {
       int totalsum =0;
       int n = nums.size();
       for(int i=0; i<n; i++){
            totalsum += nums[i];
       }
       int curr = 0;
       int result =0;
       for(int i=0;i<n;i++){
        curr += nums[i];
        if(nums[i] == 0){
            int leftsum = curr;
            int rightsum = totalsum - curr;

            if(leftsum == rightsum){
                result += 2;
            }
            if(abs(leftsum - rightsum) == 1){
                result += 1;
            }
        }
       }
       return result;
    }
};



//////////////////////////////////////////

// class Solution {
// public:
//     bool check(vector<int>nums,int count , int i ,int dirn){
//         int idx = i;
//         vector<int> temp = nums;
//         while(idx >= 0 && idx < nums.size() && count > 0){
//             if(temp[idx] > 0){
//                 temp[idx]--;
//                 dirn *= -1;
//                 if(temp[idx] == 0){
//                     count--;
//                 }
//             } 
//             idx += dirn;
//         }
//         // if(count == 0){
//         //     return true;
//         // }
//         // return false;

//         /////////or 

//         return count == 0;
//     }
//     int countValidSelections(vector<int>& nums) {
//         int count =0;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             if(nums[i] != 0){
//                 count++;
//             }
//         }
//         int result =0;
//         for(int i=0;i<n;i++){
//             if(nums[i] == 0){
//                 if(check(nums,count,i,-1)){ /// for left direction
//                     result++;
//                 }
//                 if(check(nums,count,i,1) == true){ /// for right direction
//                     result++;
//                 }
//             }
//         }
//         return result;
//     }
// };