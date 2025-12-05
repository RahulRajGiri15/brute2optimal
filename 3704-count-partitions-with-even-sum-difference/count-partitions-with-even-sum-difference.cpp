class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int>presum(n+1,0);
        for(int i=0;i<n;i++){
            presum[i+1] = presum[i] + nums[i];
        }
        int count = 0;
        for(int i = 0; i<n-1; i++){ ///n-1 because we don't want right side to be empty
            int leftsum = presum[i+1]; ///(0 ... i+1)
            int rightsum = presum[n] - presum[i+1];
            if(abs(rightsum - leftsum) %2 == 0){
                count++;
            }
        }
    return count;
    }
};