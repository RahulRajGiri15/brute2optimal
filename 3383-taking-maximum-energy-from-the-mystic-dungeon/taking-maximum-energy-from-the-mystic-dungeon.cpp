// class Solution {
// public:
//     int maximumEnergy(vector<int>& energy, int k) {
//         int n = energy.size();
//         int maxsum = INT_MIN;
//         for(int i=0;i<energy.size();i++){
//             int sum =0;
//             int j = i;
//             while(j < n){
//                 sum = sum + energy[j];
//                 j = j+k;
//             }
//             maxsum = max(maxsum,sum);
//         }
//         return maxsum;
//     }
// };


////////////////////////

class Solution {
public:
    int n ;
    int solve(vector<int>& energy,int i,int k,vector<int>&dp){
                if(i >= n) return 0;
                if(dp[i] != INT_MIN) return dp[i];
                return dp[i] = energy[i] + solve(energy,i+k,k,dp);
        }
    int maximumEnergy(vector<int>& energy, int k) {
        n = energy.size();
        int maxsum = INT_MIN;
        vector<int>dp(n,INT_MIN);
        for(int i=0;i<energy.size();i++){
            maxsum = max(maxsum , solve(energy,i,k,dp));
        }
        return maxsum;
    }
};