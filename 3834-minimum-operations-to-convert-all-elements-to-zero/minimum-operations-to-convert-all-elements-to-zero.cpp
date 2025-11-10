// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         unordered_set<int> st(nums.begin(),nums.end());
//         int n = nums.size();
//         int ops = 0;

     
//         for(int target : st){
//             if(target == 0){
//                 continue;
//             }
//             bool flow = false;
//             for(int i=0;i<n;i++){
//                 if(target == nums[i]){
//                     if(flow != true){
//                         flow = true;
//                         ops++;
//                     }
//                 }
//                 else if(nums[i] < target){
//                     flow = false;
//                 }
//             }
//         }
//         return ops;
//     }
// };


//////////////////////////////


class Solution {
public:
    int minOperations(vector<int>& nums) {
       int n = nums.size();
       stack<int> st; ////use monotonic -increasing stack concept here 
        int ops =0;
       for(int i=0;i<n;i++){
            while(!st.empty() && st.top() > nums[i]){
                st.pop();
            }
            if(nums[i] == 0){
                continue;
            }
           
            if(st.empty() || st.top() < nums[i]){
                st.push(nums[i]);
                ops++;
            }
       }
       return ops;
    }
};