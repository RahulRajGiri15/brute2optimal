
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

///t--o(V+E)
///s--o(v+E)

///////////////without using any extra space

// class Solution {
// public:
//     int V;
//     void DFS(vector<vector<int>>& isConnected,int u,vector<bool>& visited){
//         visited[u] = true;

//         for(int v=0; v<V; v++){
//             if(visited[v] == false && isConnected[u][v] == 1){
//                 DFS(isConnected,v,visited);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         V = isConnected.size();
        
//         ///now write code for dfs
//         vector<bool>visited(V,false);
//         int cnt = 0 ; 
//         for(int i=0;i<V;i++){
//             if(visited[i] == false){
//                 DFS(isConnected,i,visited);
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };

///t--o(V+E)
///s--o(V)


///////////////////////Using BFS /////////////////

// class Solution {
// public:
//     void BFS(vector<vector<int>>& adj,int u,vector<bool>& visited){
//         visited[u] = true;
//         queue<int>que;
//         que.push(u);
//         while(!que.empty()){
//             int u = que.front();
//             que.pop();
//             for(auto &v : adj[u]){
//                 if(visited[v] == false){
//                     que.push(v);
//                     visited[v] = true;
//                 }
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//        int  V = isConnected.size();
//         vector<vector<int>>adj(V);
//         for(int i=0;i<V;i++){
//             for(int j=0;j<V;j++){
//                 if(isConnected[i][j] == 1){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }
//         int cnt=0;
//         vector<bool>visited(V,false);
//         for(int i=0;i<V;i++){
//             if(visited[i] == false){
//                 BFS(adj,i,visited);
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };


//////////without using extra space /// using BFS


// class Solution {
// public:
//     void BFS(vector<vector<int>>& isConnected, int u, vector<bool>& visited){
//         int V = isConnected.size();
//         visited[u] = true;
//         queue<int>que;
//         que.push(u);
//         while(!que.empty()){
//             int u = que.front();
//             que.pop();
//             for(int v=0; v<V; v++){
//                 if(visited[v] == false && isConnected[u][v] == 1){
//                     que.push(v);
//                     visited[v] = true;
//                 }
//             }
//         }
//     }

//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int  V = isConnected.size();

//         int cnt=0;
//         vector<bool>visited(V,false);
//         for(int i=0;i<V;i++){
//             if(visited[i] == false){
//                 BFS(isConnected,i,visited);
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };


////////////////////////////


// class Solution {
// public:
//     void DFS(vector<vector<int>>& adj,int u,vector<bool>& visited){
//         visited[u] =true;
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
//         vector<bool>visited(V,false);
//         int count = 0;
//         for(int i=0;i<V;i++){
//             if(visited[i] == false){
//                 DFS(adj,i,visited);
//                 count++;
//             }
//         }
//         return count;
//     }
// };

/////////////


// class Solution {
// public:
//     int V;
//     void DFS(vector<vector<int>>& isConnected,int u,vector<bool>& visited){
//         visited[u] =true;
//         for(int v=0;v<V;v++){
//             if(visited[v] == false && isConnected[u][v] == 1){
//                 DFS(isConnected,v,visited);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         V = isConnected.size();
        
//         vector<bool>visited(V,false);
//         int count = 0;
//         for(int i=0;i<V;i++){
//             if(visited[i] == false){
//                 DFS(isConnected,i,visited);
//                 count++;
//             }
//         }
//         return count;
//     }
// };

///////////////////////DFS

// class Solution {
// public:
//     int V;
//     void DFS(vector<vector<int>>& isConnected,int u,vector<bool>& visited){
//         visited[u] =true;
//         queue<int>que;
//         que.push(u);
//         while(!que.empty()){
//             int u = que.front();
//             que.pop();
//             for(int v =0;v<V;v++){
//                 if(visited[v] == false && isConnected[u][v] == 1){
//                     que.push(v);
//                     visited[v] = true;
//                 }
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         V = isConnected.size();
        
//         vector<bool>visited(V,false);
//         int count = 0;
//         for(int i=0;i<V;i++){
//             if(visited[i] == false){
//                 DFS(isConnected,i,visited);
//                 count++;
//             }
//         }
//         return count;
//     }
// };

//////////////////////


// class Solution {
// public:
//     int V;
//     void dfss(vector<vector<int>>&adj,vector<bool>&visited,int u){
//         visited[u] = true;
//         for(auto &v : adj[u]){
//             if(visited[v] == false){
//                 dfss(adj,visited,v);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         V = isConnected.size();
//         vector<vector<int>> adj(V);
//         for(int u=0;u<V;u++){
//             for(int v=0;v<V;v++){
//                 if(isConnected[u][v] == 1){
//                     adj[u].push_back(v);
//                     adj[v].push_back(u);
//                 }
//             }
//         }
//         vector<bool>visited(V,false);
//         int count = 0;
//         for(int i=0;i<V;i++){
//             if(visited[i] == false){
//                 dfss(adj,visited,i);
//                 count++;
//             }
//         }
//         return count;
//     }
// };


///////////////////////////////////////////

// class Solution {
// public:
//     int V;
//     void dfss(vector<vector<int>>&isConnected,vector<bool>&visited,int u){
//         visited[u] = true;
//         for(int v=0;v<V;v++){
//             if(visited[v] == false && isConnected[u][v] == 1){
//                 dfss(isConnected,visited,v);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         V = isConnected.size();
//         vector<bool>visited(V,false);
//         int count = 0;
//         for(int i=0;i<V;i++){
//             if(visited[i] == false){
//                 dfss(isConnected,visited,i);
//                 count++;
//             }
//         }
//         return count;
//     }
// };

///////////////////bfs

class Solution {
public:
    int V;
    void dfss(vector<vector<int>>&isConnected,vector<bool>&visited,int u){
        visited[u] = true;
        queue<int>que;
        que.push(u);
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(int v=0;v<V;v++){
                if(visited[v] == false && isConnected[u][v] ==1){
                    dfss(isConnected,visited,v);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        V = isConnected.size();
        vector<bool>visited(V,false);
        int count = 0;
        for(int i=0;i<V;i++){
            if(visited[i] == false){
                dfss(isConnected,visited,i);
                count++;
            }
        }
        return count;
    }
};
