public class Solution {
    public int MaxSubArray(int[] nums) {
        int n = nums.Length;
        int sum =0;
        int maxsum = int.MinValue;
        for(int i=0;i<n;i++){
            sum += nums[i];
            //maxsum = Max(sum,maxsum);
            if(maxsum < sum){
                maxsum = sum;
            }
            if(sum < 0){
                sum =0;
            }
        }
        return maxsum;
    }
}