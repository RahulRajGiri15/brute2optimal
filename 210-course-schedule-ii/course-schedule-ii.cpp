class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //// it is just asking to send topological sort 
        int n = numCourses;
        vector<int>indegree(n,0);
        vector<int>result;
        //vector<vector<int>>&adj(n);
        unordered_map<int,vector<int>>adj;
        for(auto &num : prerequisites){
            int u = num[0];
            int v = num[1];
            ////v--->u
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int>que;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                que.push(i);
            }
        }
        /////writing bfs
        while(!que.empty()){
            int u = que.front();
            que.pop();
            result.push_back(u);
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    que.push(v);
                }
            }
        }
        //return (result.size() == n)? result : vector<int>();
        if(result.size() == n){
            return result;
        }
        return vector<int>();
    }
};