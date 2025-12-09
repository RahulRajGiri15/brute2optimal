// class Solution {
// public:
//     int specialTriplets(vector<int>& nums) {
//         int count = 0;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k = j+1;k<n;k++){
//                     if(nums[i] == nums[j]*2 && nums[k] == nums[j]*2){
//                         count++;
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };

///////////////////////

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int M = 1e9 + 7;
        int n = nums.size();
        unordered_map<int,int>leftmp;
        unordered_map<int,int>rightmp;
        for(int i=0;i<n;i++){
            rightmp[nums[i]]++;
        }
        int count =0;
        for(int i=0;i<n;i++){
            rightmp[nums[i]]--;
            if(leftmp.contains(nums[i]*2) && rightmp.contains(nums[i]*2)){
                count = (count + (1LL * leftmp[nums[i]*2] * rightmp[nums[i]*2])) % M;
            }
            leftmp[nums[i]]++;
        }
        return count;
    }
};