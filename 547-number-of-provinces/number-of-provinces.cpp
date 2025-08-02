

// class Solution {
// public:
//     void DFS(vector<vector<int>>& adj,int u,vector<bool>& visited){
//         visited[u] = true;
//         for(auto &v : adj[u]){
//             if(visited[v] == false){
//                 DFS(adj,v,visited);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int V = isConnected.size();
//         vector<vector<int>>adj(V);
//         for(int u=0;u<V;u++){
//             for(int v=0;v<V;v++){
//                 if(isConnected[u][v] == 1){
//                     adj[u].push_back(v);
//                     adj[v].push_back(u);
//                 }
//             }
//         }
//         ///now write code for dfs
//         vector<bool>visited(V,false);
//         //vector<int> result;
//         int cnt = 0 ; 
//         for(int i=0;i<V;i++){
//             if(visited[i] == false){
//                 DFS(adj,i,visited);
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };

///////////optimal solution ---storing the dfs in result

// class Solution {
// public:
//     void DFS(vector<vector<int>>& adj,int u,vector<bool>& visited,vector<int>& result){
//         visited[u] = true;
//         result.push_back(u);
//         for(auto &v : adj[u]){
//             if(visited[v] == false){
//                 DFS(adj,v,visited,result);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int V = isConnected.size();
//         vector<vector<int>>adj(V);
//         for(int u=0;u<V;u++){
//             for(int v=0;v<V;v++){
//                 if(isConnected[u][v] == 1){
//                     adj[u].push_back(v);
//                     adj[v].push_back(u);
//                 }
//             }
//         }
//         ///now write code for dfs
//         vector<bool>visited(V,false);
//         vector<int> result;
//         int cnt = 0 ; 
//         for(int i=0;i<V;i++){
//             if(visited[i] == false){
//                 DFS(adj,i,visited,result);
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };

///////////////using unordered map 


// class Solution {
// public:
//     void DFS(unordered_map<int, vector<int>>& adj,int u,vector<bool>& visited,vector<int>& result){
//         visited[u] = true;
//         result.push_back(u);
//         for(auto &v : adj[u]){
//             if(visited[v] == false){
//                 DFS(adj,v,visited,result);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int V = isConnected.size();
//         //vector<vector<int>>adj(V);
//         unordered_map<int, vector<int>>adj;
//         for(int u=0;u<V;u++){
//             for(int v=0;v<V;v++){
//                 if(isConnected[u][v] == 1){
//                     adj[u].push_back(v);
//                     adj[v].push_back(u);
//                 }
//             }
//         }
//         ///now write code for dfs
//         vector<bool>visited(V,false);
//         vector<int> result;
//         int cnt = 0 ; 
//         for(int i=0;i<V;i++){
//             if(visited[i] == false){
//                 DFS(adj,i,visited,result);
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };

///////////////without using any extra space


class Solution {
public:
    int V;
    void DFS(vector<vector<int>>& isConnected,int u,vector<bool>& visited){
        visited[u] = true;

        for(int v=0; v<V; v++){
            if(visited[v] == false && isConnected[u][v] == 1){
                DFS(isConnected,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        V = isConnected.size();
        
        ///now write code for dfs
        vector<bool>visited(V,false);
        int cnt = 0 ; 
        for(int i=0;i<V;i++){
            if(visited[i] == false){
                DFS(isConnected,i,visited);
                cnt++;
            }
        }
        return cnt;
    }
};