class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1000000007;
        vector<int>power;
        for(int i=0;i<32;i++){
            if(n & (1<<i)){
                power.push_back(1<<i);
            }
        }
        vector<int>ans;
        for(auto &arr : queries){
            int i = arr[0];
            int j = arr[1];
            long long pro = 1;
            for(int num=i;num<=j;num++){
                pro = (pro * power[num]) % mod;
            }
            //pro = pro % mod;
            ans.push_back((int)pro);
        }
        return ans;
    }
};