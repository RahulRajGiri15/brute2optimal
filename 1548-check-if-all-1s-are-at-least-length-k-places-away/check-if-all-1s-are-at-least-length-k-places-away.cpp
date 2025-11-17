class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int count =0;
        int prev =0;
        int next = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                prev = i; /// now our prev is at first i
                break;
            }
        }
        for(int i=prev +1;i<n;i++){
            if(nums[i] == 1){
                next = i;
                if((next-prev - 1) < k){
                    return false;
                }
                prev = next;
            }
        }
        return true;
    }
};

///////////

// class Solution {
// public:
//     bool kLengthApart(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count =0;
//         int prev =0;
//         int next = 0;
//         prev = -(k + 1); //// let last time seen 1 be at --> next-prev - 1 > k -- for 1 at idx 0
//         for(int i= 0;i<n;i++){
//             if(nums[i] == 1){
//                 next = i;
//                 if((next-prev - 1) < k){
//                     return false;
//                 }
//                 prev = next;
//             }
//         }
//         return true;
//     }
// };