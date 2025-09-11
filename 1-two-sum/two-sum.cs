// public class Solution {
//     public int[] TwoSum(int[] nums, int target) {
//         for(int i=0;i<nums.Length;i++){
//             for(int j=i+1;j<nums.Length;j++){
//                 if(nums[i]+nums[j] == target){
//                     return new int[] {i,j};
//                 }
//             }
//         }
//         return new int[]{};
//     }
// }

/////////////////


public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int , int> dict = new Dictionary<int ,int>();
        for(int i=0;i<nums.Length;i++){
            int rem  = target - nums[i];
            if(dict.ContainsKey(rem)){
                return new int[] {dict[rem] , i};
            }
            dict[nums[i]] = i;
        }
        return new int[] {};
    }
}