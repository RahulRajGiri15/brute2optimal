// class Solution {
// public:
//     int minSubarray(vector<int>& nums, int p) {
//         long long sum = 0;
//         int n = nums.size();
//         for(int i=0;i<nums.size();i++){
//             sum += nums[i];
//         }
        
//         int r = sum % p;
//         if(r == 0) return 0;
//         int res = INT_MAX;
//         for(int i=0;i<n;i++){
//             long long summ = 0;
//             for(int j=i;j<n;j++){
//                 summ +=nums[j];
//                 if(summ %p == r){
//                     int len = j-i+1;
//                     if(len < n)                
//                         res = min(res, len);
                
//                 }
//             }
//         }
//         return res == INT_MAX ? -1: res;
//     }
// };

////////////////////

// class Solution {
// public:
//     int minSubarray(vector<int>& nums, int p) {
//         int sum = 0;
//         int n = nums.size();
//         for(int i=0;i<nums.size();i++){
//             sum += (nums[i]);
//         }
        
//         int r = sum % p;
//         if(sum < p) return -1;
//         if(r == 0) return 0;
//         int res = INT_MAX;
//         for(int i=0;i<n;i++){
//             int summ = 0;
//             for(int j=i;j<n;j++){
//                 summ +=nums[j];
//                 if(summ == r){
//                     res = min(res, j-i+1);
//                 }
//             }
//         }
//         return res == INT_MAX ? -1: res;
//     }
// };

////////////////////////

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int SUM = 0;

        //(a+b)%p = (a%p + b%p) % p
        for(int &num : nums) {
            SUM = (SUM + num) % p;
        }

        int target = SUM%p;

        if(target == 0) {
            return 0;
        }

        unordered_map<int, int> mp; //prev sum%p ko store karega

        int curr = 0;
        mp[0] = -1;

        int result = n;
        for(int j = 0; j < n; j++) {
            curr = (curr + nums[j]) % p;

            int remain = (curr - target + p) % p;
            if(mp.find(remain) != mp.end()) {
                result = min(result, j - mp[remain]);
            }

            mp[curr] = j;
        }

        return result == n ? -1 : result;

    }
};



