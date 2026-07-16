class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        vector<int>pf(n);
        for(int i=0;i<n;i++){
            maxi = max(maxi, nums[i]);
            pf[i] = gcd(nums[i], maxi);
        }
        sort(pf.begin(), pf.end());
        long long sum =0, l = 0, r = n-1;
        while(l<r){
            sum += gcd(pf[l], pf[r]);
            l++;
            r--;
        }
        return sum;
    }
};