////int his we just have to detect cycle in graph
////if cycle is present than false otherwise true

/////detect cycle in graph -- directed graph -- BFS || DFS
////for directed acyclic graph using BFS -- khan's algorithm is best 

// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int,vector<int>>adj;
//         vector<int>indegree(numCourses,0);
//         for(auto &vec : prerequisites){
//                 int i = vec[0];
//                 int j = vec[1];
//                 ///j--->a
//                 adj[j].push_back(i);
//                 indegree[i]++;

//             }
//         int count = 0;
//         queue<int> que;
//         for(int v=0;v<numCourses;v++){
//             if(indegree[v] == 0){
//                 que.push(v);
//                 count++;
//             }
//         }
//         while(!que.empty()){
//             int u = que.front();
//             que.pop();

//             for(auto &v : adj[u]){
//                 indegree[v]--;

//                 if(indegree[v] == 0){
//                     que.push(v);
//                     count++;
//                 }
//             }
//         }
//         if(count == numCourses) return true;
//         return false;
//     }
// };

////////////////topological sorting


// class Solution {
// public:

//     bool topodfs(unordered_map<int,vector<int>>& adj,int numCourses, vector<int>& indegree){
//         int count = 0;
//         queue<int> que;
//         for(int v=0;v<numCourses;v++){
//             if(indegree[v] == 0){
//                 que.push(v);
//             }
//         }
//         while(!que.empty()){
//             int u = que.front();
//             que.pop();
//              count++;
//             for(auto &v : adj[u]){
//                 indegree[v]--;

//                 if(indegree[v] == 0){
//                     que.push(v);
                   
//                 }
//             }
//         }
//         if(count == numCourses) return true;
//         return false;

//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int,vector<int>>adj;
//         vector<int>indegree(numCourses,0);
//         for(auto &vec : prerequisites){
//                 int i = vec[0];
//                 int j = vec[1];
//                 ///j--->a
//                 adj[j].push_back(i);
//                 indegree[i]++;

//         }
//         return topodfs(adj,numCourses,indegree);
        
//     }
// };

///////////cylce detection -- topologocal sort

// class Solution {
// public:
//     int n;
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int,vector<int>>adj;
//         n = numCourses;
//         vector<int>indegree(n,0);
//         for(auto &num : prerequisites){
//                 int u = num[0];
//                 int v = num[1];
//                 adj[v].push_back(u);
//                 indegree[u]++;
//         }
        
//         // for(int i=0;i<n;i++){
//         //     for(int &t : adj[i]){
//         //         indegree[t]++;
//         //     }
//         // }
//         queue<int>que;
//         for(int i=0;i<n;i++){
//             if(indegree[i] == 0){
//                 que.push(i);
//             }
//         }
//         ///// bfs
//         int count =0;
//         while(!que.empty()){
//             int u= que.front();
//             que.pop();
//             count++;
//             for(auto v : adj[u]){
//                 indegree[v]--;
//                 if(indegree[v] == 0){
//                     que.push(v);
//                 }
//             }
//         }
//         if(count == n){
//             return true; /// no cycle is present 
//         }
//         return false;
//     }
// };


//////////////06-09-2025 --- in this we will use DFS to solve this 

class Solution {
public:
    int n;
    bool iscycle(vector<vector<int>>&adj,int u,vector<bool>&visited,vector<bool>&inrecursion){
        visited[u] = true;
        inrecursion[u] = true;
        for(auto &v : adj[u]){
            if(visited[v] == false && iscycle(adj,v,visited,inrecursion)){
                return true;
            }
            else if(inrecursion[v] == true){
                return true;
            }
        } 
        inrecursion[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //// first make adjency matrix / list
        n = numCourses;
        vector<vector<int>> adj(n);
        for(auto &num : prerequisites){
            int u = num[0];
            int v = num[1];
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        vector<bool>inrecursion(n,false);
        for(int i=0;i<n;i++){
            if(visited[i] == false && iscycle(adj,i,visited,inrecursion)){ 
                return false; ///////if cycle is present
            }
        }
        return true;
    }
};
