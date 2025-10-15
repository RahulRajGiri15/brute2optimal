class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int prevrun = 0;
        int currun = 1;
        int k = 0;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                currun++;
            }
            else{
                prevrun = currun;
                currun = 1;
            }
            k = max(k,currun/2);
            k = max(k , min(prevrun , currun));
        }
        return k;
    }
};