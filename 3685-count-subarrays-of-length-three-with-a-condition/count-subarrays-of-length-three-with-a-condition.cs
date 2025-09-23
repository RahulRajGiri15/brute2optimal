public class Solution {
    public int CountSubarrays(int[] nums) {
        int n = nums.Length;
        int count =0;
          
        for(int i=0;i<n-2;i++){
            if(nums[i+1] %2 == 0 && nums[i]+nums[i+2] == (nums[i+1]/2)){
                count++;
            }
        }
        return count;

    }
}