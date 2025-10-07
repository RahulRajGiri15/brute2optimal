// class Solution {
// public:
//     int solve(vector<int>& nums, int i,int ns){
//         if(i > ns){
//             return 0;
//         }
//         int steal = nums[i] + solve(nums,i+2,ns);
//         int skip = solve(nums,i+1,ns);

//         return max(steal,skip);
//     }
//     int rob(vector<int>& nums) {
//         if(nums.size() == 1){
//             return nums[0];
//         }
//         int n = nums.size() -1;
//         int first = solve(nums , 0, n-1); ///if choosing first than don't take last elemnt in ar
//         int second = solve(nums, 1 , n); ///if choosing second than don't take first in arr

//         return max (first,second);
//     }
// };


/////////////////////////////////

class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i,int ns){
        if(i > ns){
            return 0;
        }
        if(t[i] != -1) return t[i];
        int steal = nums[i] + solve(nums,i+2,ns);
        int skip = solve(nums,i+1,ns);

        return t[i] =  max(steal,skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        
        int n = nums.size() ;
        memset(t, -1,sizeof(t));
        int first = solve(nums , 0, n-2); ///if choosing first than don't take last elemnt in ar
        memset(t, -1,sizeof(t));
        int second = solve(nums, 1 , n-1); ///if choosing second than don't take first in arr

        return max(first,second);
    }
};