////////////topological sorting in BFS(using queue)

// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         //// it is just asking to send topological sort 
//         int n = numCourses;
//         vector<int>indegree(n,0);
//         vector<int>result;
//         //vector<vector<int>>&adj(n);
//         unordered_map<int,vector<int>>adj;
//         for(auto &num : prerequisites){
//             int u = num[0];
//             int v = num[1];
//             ////v--->u
//             adj[v].push_back(u);
//             indegree[u]++;
//         }
//         queue<int>que;
//         for(int i=0;i<n;i++){
//             if(indegree[i] == 0){
//                 que.push(i);
//             }
//         }
//         /////writing bfs
//         while(!que.empty()){
//             int u = que.front();
//             que.pop();
//             result.push_back(u);
//             for(int &v : adj[u]){
//                 indegree[v]--;
//                 if(indegree[v] == 0){
//                     que.push(v);
//                 }
//             }
//         }
//         //return (result.size() == n)? result : vector<int>();
//         if(result.size() == n){
//             return result;
//         }
//         return vector<int>();
//     }
// };

////////////////////////////in this we have to return order 
/////////////////////////use DFS + topological sorting in DFS(use stack)


// class Solution {
// public:
//     int n;
//     bool dfsorder(unordered_map<int,vector<int>>&adj,int u ,vector<bool>&visited,vector<bool>&inrecursion,stack<int>&st){
//         visited[u] = true;
//         inrecursion[u] = true;
//         for(auto &v : adj[u]){
//             if(visited[v] == false && dfsorder(adj,v,visited,inrecursion,st)){
//                 return true; /// cycle detected
//             }
//             if(inrecursion[v] == true){
//                 return true; /// cycle is present
//             }
//         }
//         st.push(u);
//         inrecursion[u] = false;
//         return false;
//     }
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         //// it is just asking to send topological sort 
//         n = numCourses;
//         unordered_map<int,vector<int>> adj;
//         for(auto &num : prerequisites){
//             int u = num[0];
//             int v = num[1];
//             ///v-->u
//             adj[v].push_back(u);
//         }
//         vector<bool> visited(n,false);
//         vector<bool> inrecursion(n,false);
//         vector<int>result;
//         stack<int>st;
//         for(int i=0;i<n;i++){
//             if(visited[i] == false){
//                 if(dfsorder(adj,i,visited,inrecursion,st) == true ){ //cycle present
//                     return {};
//                 }
//             }
//         }
//         while(!st.empty()){
//             result.push_back(st.top());
//             st.pop();
//         }
//         return result.size() == n ? result: vector<int>();
//     }
// };


///////////////////

////////////////////////////in this we have to return order 
/////////////////////////use DFS + topological sorting in DFS(use stack)


class Solution {
public:
    int n;
    bool hascycle = false;
    void dfsorder(unordered_map<int,vector<int>>&adj,int u ,vector<bool>&visited,vector<bool>&inrecursion,stack<int>&st){
        visited[u] = true;
        inrecursion[u] = true;
        ////pahle u -> ke bachoo (v) do stack me dono 
        for(auto &v : adj[u]){
            if(inrecursion[v] == true){
                hascycle  = true;
                return ;
            }
            if(visited[v] == false){
                dfsorder(adj,v,visited,inrecursion,st);
            }
        }
        st.push(u); //phir parent (u) ko dalo
        inrecursion[u] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //// it is just asking to send topological sort 
        n = numCourses;
        unordered_map<int,vector<int>> adj;
        for(auto &num : prerequisites){
            int u = num[0];
            int v = num[1];
            ///v-->u
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        vector<bool> inrecursion(n,false);
        vector<int>result;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(visited[i] == false){
                dfsorder(adj,i,visited,inrecursion,st);
            }
        }
        if(hascycle == true){
            return {};
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        //return result.size() == n ? result: vector<int>();
        return result;
    }
};
