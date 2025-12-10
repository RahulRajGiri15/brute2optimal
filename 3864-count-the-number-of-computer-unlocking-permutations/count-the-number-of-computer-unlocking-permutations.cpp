class Solution {
public:
    int M = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int result = 1;
        for(int i=1;i<n;i++){
            if(complexity[i] <= complexity[0] ){
                return 0;
            }
            result = (1LL * result * i) % M;
        }
        return result;
    }
};