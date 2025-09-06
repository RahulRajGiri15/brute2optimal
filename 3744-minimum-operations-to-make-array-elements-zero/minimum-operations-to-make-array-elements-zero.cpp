class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        
        long long  result = 0;
        for(auto &num : queries){
            long long s = 1;
            int l = num[0] , r = num[1];
            long long L = 1, R = 1;
            long long  start = 0 , end =0;
            long long steps = 0;
            
            while(L <= r){
                R = 4 * L -1;
               
                start = max((long long) l,L);
                end = min((long long) r,R);
                if(start <= end){
                    steps += (end-start+1)*s;
                }
                s +=1;
                L = L*4;
            }
            result += (steps+1)/2;
        }
        return result;
    }
};