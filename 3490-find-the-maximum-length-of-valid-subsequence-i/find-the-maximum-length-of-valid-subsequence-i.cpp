class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int cntE=0,cntO=0;
        for(int i=0;i<n;i++){
            if(nums[i] %2 == 0){
                cntE++;
            }
            else if(nums[i]%2 != 0){
                cntO++;
            }
        }
        int parity = nums[0]%2;
        int alternating=1;
        for(int i=1;i<n;i++){
            int currpar = nums[i]%2;
            if(currpar != parity){
                alternating++;
                parity = currpar;
            }
        }
        // int maxx = max(cntE,cntO);
        // return max(maxx , alternating);
        return max({cntE,cntO,alternating});
    }
};