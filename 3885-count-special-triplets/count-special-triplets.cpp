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

// class Solution {
// public:
//     int specialTriplets(vector<int>& nums) {
//         int M = 1e9 + 7;
//         int n = nums.size();
//         unordered_map<int,int>leftmp;
//         unordered_map<int,int>rightmp;
//         for(int i=0;i<n;i++){
//             rightmp[nums[i]]++;
//         }
//         int count =0;
//         for(int i=0;i<n;i++){
//             rightmp[nums[i]]--;
//             if(leftmp.contains(nums[i]*2) && rightmp.contains(nums[i]*2)){
//                 count = (count + (1LL * leftmp[nums[i]*2] * rightmp[nums[i]*2])) % M;
//             }
//             leftmp[nums[i]]++;
//         }
//         return count;
//     }
// };

//////////////////////

class Solution {
public:
    int M = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
       
        int n = nums.size();
        unordered_map<int,int>valid_i;
        unordered_map<int,int>valid_j;
        int result = 0;
        for (int &num : nums){
            ///try to find valid_k
            if(num % 2 == 0){
                result = (result + valid_j[num/2]) % M;
            }
            ///try finding valid j
            valid_j[num] = (valid_j[num] + valid_i[num * 2]) % M;

            valid_i[num]++;
        }

        return result;
    }
};

