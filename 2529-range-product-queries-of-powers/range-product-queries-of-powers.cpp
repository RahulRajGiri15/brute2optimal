class Solution {
public:
    int mod = 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        //int mod = 1000000007;
        vector<int>power; ///max -o(32)
        for(int i=0;i<32;i++){  ///o(1)
            ///if(n & (1<<i)){
            if((n & (1<<i)) != 0){ /// ith bit is set 
                power.push_back(1<<i);
            }
        }
        vector<int>ans;
        for(auto &arr : queries){ /// q -- number of queries ///o(qlog n)
            int i = arr[0];
            int j = arr[1];
            long long pro = 1;
            for(int num=i;num<=j;num++){ ////max -- o(32)
                pro = (pro * power[num]) % mod;
            }
            //pro = pro % mod;
            ans.push_back((int)pro);
        }
        return ans;
    }
};

///t--o(q)--for query + o(32)-for power -- o(32)-->o(q)
///s -- o(32)--for power + o(q)--for result--->o(q)