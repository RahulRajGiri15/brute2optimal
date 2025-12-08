// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int>pq;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             if(pq.size() < k){
//                 pq.push(nums[i]);
//             }
//             else if(nums[i] > pq.top()){
//                 pq.pop();
//                 pq.push(nums[i]);
//             }
//         }
//         return pq.top();
//     }
// };

////////////////////

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        int i = pq.top();
        return i;
    }
};