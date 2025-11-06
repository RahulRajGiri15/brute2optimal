class Solution {
public:
    void dfs(int node, unordered_map<int,vector<int>>& adj, int id,vector<int>& nodeid,unordered_map<int,set<int>> &mp,vector<bool> &visited){
        visited[node] = true;
        mp[id].insert(node);
        nodeid[node] = id;
        ///o(c+n)
        for(int &ngbr : adj[node]){
            if(!visited[ngbr]){
                dfs(ngbr,adj,id,nodeid,mp,visited);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>>adj;
        for(auto &edge : connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(c+1,false);
        vector<int> nodeid(c+1);
        ///id -> {}
        unordered_map<int,set<int>>mp;
        for(int node =1 ; node<=c;node++){
            if(!visited[node]){
                int id = node;
                dfs(node ,adj, id,nodeid,mp,visited);
            }
        }

        vector<int>result;
        ///o(q * log c)
        for(auto &query : queries){
            int type = query[0]; ///1 ,2
            int node = query[1]; ///station ,node
            if(type == 1){
                int id = nodeid[node];
                if(mp[id].count(node)){
                    result.push_back(node);
                }
                else if(!mp[id].empty()){
                    result.push_back(*mp[id].begin());//insert the smallest element
                }
                else{
                    result.push_back(-1);
                }
            }
                else{
                    int id = nodeid[node];
                    mp[id].erase(node);///log c
                }
            }
        return result;
    }
};