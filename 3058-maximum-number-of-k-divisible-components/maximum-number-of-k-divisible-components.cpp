class Solution {
public:
    int count;
    int dfs(int curr , int parent, unordered_map<int,vector<int>>& adj,vector<int>& values, int k){
        int sum = values[curr];
        for(auto &ngbr : adj[curr]){
            if(ngbr != parent){
                sum += dfs(ngbr , curr, adj,values,k);
                sum = sum % k;
            }
        }
        sum = sum % k;
        if(sum == 0){
            count++;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>>adj;
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        count  = 0;
        dfs(0, -1 ,adj, values,k);
        return count;
    }
};