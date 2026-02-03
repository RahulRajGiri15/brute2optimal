// class Solution {
// public:
//     bool isTrionic(vector<int>& nums) {
//         int p = 0;
//         int q = 0;
//         int n;
//         n = nums.size();
//         for(int i=0;i<n;i++){
//             if(nums[i+1] > nums[i] && q == 0){
//                 p = i+1;
//             }
//             else if(nums[i] < nums[i-1] && p != 0){
//                 q = i;
//             }
//         }
//         if(p == q) return false;
//         if(nums[q] == nums[n-1])return false;
//         if(0 < p && p < q && q < n-1){
//             return true;
//         }
//         return false;
//     }
// };

// 

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return false; // need three segment
        int p =0;
        while(p+1 < n && nums[p+1] > nums[p]){
            p++;
        }
        if(p == 0) return false; // no increasing part
        int q = p;
        while(q+1 < n && nums[q+1] < nums[q]){
            q++;
        } 
        if(q == p) return false; // no decreasing
        int k = q; // for increasin cehck
        while(k+1 < n && nums[k+1] > nums[k]){
            k++;
        }
        if(k == q) return false; // no increasing part
        return k == n-1;
    }
};

