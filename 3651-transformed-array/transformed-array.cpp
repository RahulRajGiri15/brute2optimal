class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            int shift = nums[i] %n ; ///for values to be 0 to n-1
            int newidx = (i+shift) % n;
            if(newidx < 0){
                newidx +=n;
            }
            result[i] = nums[newidx];
        }
        return result;
    }
};