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


// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int>pq;
//         for(int i=0;i<nums.size();i++){
//             pq.push(nums[i]);
//         }
//         for(int i=0;i<k-1;i++){
//             pq.pop();
//         }
//         int i = pq.top();
//         return i;
//     }
// };


////////////////////Hoore  partitaion ---> greater (left) < pivot < smaller (right)

// class Solution {
// public:
//     int partitation(int left, int right ,vector<int>& nums){
//         int pivot = nums[left];
//         int i = left+1;
//         int j = right;
//         while(i <= j){
//             if(nums[i] < pivot && nums[j] > pivot){
//                 swap(nums[i],nums[j]);
//                 i++;
//                 j--;
//             }
//             if(nums[i] >= pivot){
//                 i++;
//             }
//             if(nums[j] <= pivot){
//                 j--;
//             }
//         }
//         swap(nums[left],nums[j]);
//         return j;
//     }
//     int findKthLargest(vector<int>& nums, int k) {
//         int n = nums.size();
//         int L = 0;
//         int R = n-1;
//         int pivot_idx = 0;

//         while(true){

//             pivot_idx = partitation(L,R, nums);
//             if(pivot_idx ==  k-1){
//                 break;
//             }
//             else if(pivot_idx > k-1){
//                 R = pivot_idx - 1;
//             }
//             else{
//                 L = pivot_idx + 1;
//             }
//         }
//         return nums[pivot_idx];
//     }
// };

/////////////////////////

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            if(pq.size() < k){
                pq.push(nums[i]);
            }
            else if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }    
        }
        return pq.top();
    }
};
