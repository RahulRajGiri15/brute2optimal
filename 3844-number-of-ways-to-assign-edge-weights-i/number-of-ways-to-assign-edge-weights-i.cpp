class Solution {
public:
    const int MOD=1e9+7;
int power(long long a,long long b){
    long long ans=1;
        a%=MOD;
     while(b>0){
        if(b&1)ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return (int)ans;
}
    int dfs(int node,int per,vector<vector<int>>&adj){
        if(adj[node].size()==0)return 0;
        int ans=0;
        for(auto&it:adj[node]){
            if(it!=per)ans=max(ans,1+dfs(it,node,adj));
        }
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+2;
        vector<vector<int>>adj(n);
        for(auto&edge : edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int depth=dfs(1,-1,adj);
        return power(2,depth-1);
    }
};