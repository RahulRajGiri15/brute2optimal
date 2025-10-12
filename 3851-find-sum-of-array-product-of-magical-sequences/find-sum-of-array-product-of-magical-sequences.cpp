#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll modpow(ll a, ll e=MOD-2) {
    ll r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD; e>>=1;
    }
    return r;
}

class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        // precompute powNums[i][t] = nums[i]^t
        vector<vector<ll>> powNums(n, vector<ll>(m+1,1));
        for(int i=0;i<n;++i) for(int t=1;t<=m;++t)
            powNums[i][t] = powNums[i][t-1]*nums[i]%MOD;

        // precompute factorials for combinations
        vector<ll> fact(m+1,1), ifact(m+1,1);
        for(int i=1;i<=m;++i) fact[i]=fact[i-1]*i%MOD;
        ifact[m]=modpow(fact[m]);
        for(int i=m;i>0;--i) ifact[i-1]=ifact[i]*i%MOD;

        auto C = [&](int a,int b)->ll{
            if(b<0||b> a) return 0;
            return fact[a]*ifact[b]%MOD*ifact[a-b]%MOD;
        };

        // dp: map key (pos, carry, used, ones) -> value
        map<tuple<int,int,int,int>, ll> dp;
        function<ll(int,int,int,int)> dfs = [&](int pos, int carry, int used, int ones)->ll{
            if(used > m) return 0;
            if(pos == n) {
                if(used == m && ones + __builtin_popcount((unsigned)carry) == k) return 1;
                return 0;
            }
            auto key = make_tuple(pos, carry, used, ones);
            if(dp.count(key)) return dp[key];
            ll res = 0;
            for(int t=0; t<= m-used; ++t) {
                int sum = carry + t;
                int bit = sum & 1;
                int nextCarry = sum >> 1;
                // multiply by choice C(m-used, t) to account for permutations
                ll ways = dfs(pos+1, nextCarry, used + t, ones + bit);
                if(!ways) continue;
                ll add = powNums[pos][t] * C(m - used, t) % MOD * ways % MOD;
                res = (res + add) % MOD;
            }
            return dp[key] = res;
        };

        return (int)dfs(0, 0, 0, 0);
    }
};