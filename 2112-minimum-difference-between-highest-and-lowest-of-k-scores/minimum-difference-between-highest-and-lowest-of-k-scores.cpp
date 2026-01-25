class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i =0;
        int j = i+k-1;
        int diff = INT_MAX;
        while(j < n){
            int mini =INT_MAX;
            int maxi = INT_MIN;
            for(int r = i;r <= j;r++){
                mini = min(mini , nums[r]);
                maxi = max(maxi , nums[r]);
            }
            diff = min(diff, maxi - mini);
            i++;
            j++;
        }
        return diff;
    }
};