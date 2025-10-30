class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        vector<int>diff(n);
        int curr = 0;
        int prev = 0;
        int oper = 0;
        for(int i=0;i<n;i++){
            curr = target[i];
            /// check for sign change
            if(curr < 0 && prev > 0){
                oper += abs(curr);
            }
            if(curr > 0 && prev <0){
                oper += abs(curr);
            }
            /////if there is no case of sign change
            else if(abs(curr) > abs(prev)){
                oper += abs(curr - prev);
            }
            prev = curr;
        }
        return oper;
    }
};