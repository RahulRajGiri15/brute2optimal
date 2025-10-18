class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int prev = INT_MIN;
        int n = nums.size();
        int count =0;
        for(int i=0;i<n;i++){
            int minval = nums[i] -k;
            if(prev < minval){
                prev = minval;
                count++;
            }
            else if(prev < (nums[i]+k)){ ////////in cases prev >= minval
                prev = prev + 1;
                count++;
            }
        }
        return count;
    }
};