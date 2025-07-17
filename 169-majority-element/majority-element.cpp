////////using optimal solution

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,int>mp;
//         int n = nums.size();
//         for(int num : nums){
//             mp[num]++;
//         }
//         for(auto &it : mp){
//             if(it.second > n/2 ){
//                 return it.first;
//             }
//         }
//         return -1;
//     }
// };
/////t-o(n)
/////s-o(n)

//////////////brute solution


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             int cnt =0;
//             for(int j=0;j<n;j++){
//                 if(nums[i] == nums[j]){
//                     cnt++;
//                 }
//             }
//             if(cnt > n/2) return nums[i];
//         }
//         return -1;
//     }
// };

/////t-o(n^2)
/////s-o(1)


///////////// optimal approach

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         int cnt=0;
//         int x = nums[0];
//         for(int i =0;i<n;i++){
//             if(x == nums[i]){
//                 cnt++;
//             }
//             if(x != nums[i]){
//                 cnt--;
//             }
//             if(cnt == 0){
//                 x = nums[i];
//                 cnt++;
//             }
//         }
//         return x ; 
//     }
// };


//////////////////

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for(int num : nums){
            if(count == 0){
                candidate = num;
            }
            if( candidate == num){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};


