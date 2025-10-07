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

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1){
//             return nums[0];
//         }
//         int i=0;
//         while(i < n-1){
//             if(nums[i] != nums[i+1]){
//                 break;
//             }
//             i = i+2;
//         }
//         return nums[i];
//     }
// };


//////////////////////////

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1){
//             return nums[0];
//         }
//         int i=0;
//         while(i < n-1){
//             if(nums[i] != nums[i+1]){
//                 break;
//             }
//             i = i+2;
//         }
//         return nums[i];
//     }
// };

/////////////////////

/////////o(n)
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1){
//             return nums[0];
//         }
//         int x = nums[0];
//         int i=1;
//         while(i < n){
//             x ^= nums[i];
//             i++;
//         }
//         return x;
//     }
// };

//////////////////////////binary search

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        while(l < h){
            int mid = l + (h-l)/2;
            bool iseven;
            if((h - mid) %2 == 0){ /////right side is even
                iseven = true;
            }
            else{
                iseven = false; /////right side is odd
            }

            if(nums[mid] == nums[mid+1]){
                if(iseven){ ///// right side me odd bachee -- our ans is in right side
                    l = mid+2;
                }
                else{ /////right side me even num of element bachee  -- our ans is in left side
                    h = mid-1;
                }
            }
            else if(nums[mid] != nums[mid+1]){
                if(iseven){ ////right side is even -- than every elem has already a pair right 
                    h  =  mid;
                }
                else{
                    l = mid+1;
                }
            }
        }
        return nums[h]; ///////or nums[h]
    }
};