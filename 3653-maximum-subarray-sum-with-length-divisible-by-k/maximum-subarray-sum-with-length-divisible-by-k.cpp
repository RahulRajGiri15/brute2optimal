
//////////////////////////////////////
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxsum = LLONG_MIN;
        vector<long long>presum(n,0);
        long long sum =0;
        presum[0] = nums[0];
        for(int i =1;i<n;i++){
            presum[i] = presum[i-1] + nums[i];
        }
        for(int start = 0; start<=k-1;start++){
            long long currsum = 0;
            int i = start;
            while(i < n && i+k-1 < n){
                int j = i+k-1;

                long long subsum = presum[j] - ((i == 0)? 0:presum[i-1]);
                currsum = max(subsum , currsum + subsum);
                maxsum = max(maxsum , currsum);
                i = i+k;
            }
        }
        return maxsum;
    }
};


////////////////////////////////////////
// class Solution {
// public:
//     long long maxSubarraySum(vector<int>& nums, int k1) {
//         int n = nums.size();
//         long long maxsum = LLONG_MIN;
//         vector<long long>presum(n,0);
//         long long sum =0;
//         presum[0] = nums[0];
//         for(int i =1;i<n;i++){
//             presum[i] = presum[i-1] + nums[i];
//         }
//         for(int i=0;i<n;i++){
//             long long s = 0;
//             for(int j =i;j<n;j++){
//                 int len = j - i +1;
//                 if(len % k1 == 0){
//                     if(i == 0) s = presum[j];
//                     else s = presum[j] - presum[i-1];
//                     maxsum = max(maxsum,s);
//                 } 
//             }
//         }
//         return maxsum;
//     }
// };

///////////////////////////////////
// class Solution {
// public:
//     long long maxSubarraySum(vector<int>& nums, int k1) {
//         int n = nums.size();
//         long long maxsum = LLONG_MIN;
//         for(int i=0;i<n;i++){
//             long long sum  = 0;
//             for(int j = i;j<n;j++){ ////[i.....n]
//                 sum += nums[j];
//                 int len = j - i + 1;
//                 if((len % k1) == 0){
//                     maxsum = max(maxsum,sum);
//                 }
//             }
//         }
//         return maxsum;
//     }
// };


////////////////////////////kadnes algo

// class Solution {
// public:
//     long long maxSubarraySum(vector<int>& nums, int k1) {
//         int n = nums.size();
//         long long maxsum = LLONG_MIN;
//         for(int i=0;i<n;i++){
            
//         }
//         return maxsum;
//     }
// };



//////////////////////////////////
// class Solution {
// public:
//     long long maxSubarraySum(vector<int>& nums, int k1) {
//         int n = nums.size();
//         long long maxsum = LLONG_MIN;
//         for(int i=0;i<n;i++){
//             for(int j = i;j<n;j++){
//                 long long sum = 0;
//                 for(int k =i;k<=j;k++){
//                     sum += nums[k];
//                 }
//                 if((j - i + 1) % k1 == 0){
//                     maxsum = max(maxsum , sum);
//                 }
//             }
//         }
//         return maxsum;
//     }
// };