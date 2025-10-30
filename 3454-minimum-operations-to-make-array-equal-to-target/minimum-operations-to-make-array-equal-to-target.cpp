class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = target.size();
        int curr = 0;
        int prev = 0;
        long long oper = 0;
        for(int i=0;i<n;i++){
            curr = target[i] - nums[i];
            /// check for sign change --- in this operation
            if((curr < 0 && prev > 0) || (curr > 0 && prev <0)){
                oper += abs(curr);
            }
            /////if there is no case of sign change
            else if(abs(curr) > abs(prev)){
                oper += abs(curr - prev);
            }
            // elseif(abs(curr) <= abs(prev)){
            //     do nothing; -- because it is already included
            // }
            prev = curr;
        }
        return oper;
    }
};