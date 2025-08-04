////int his we just have to detect cycle in graph
////if cycle is present than false otherwise true

/////detect cycle in graph -- directed graph -- BFS || DFS
////for directed acyclic graph using BFS -- khan's algorithm is best 

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto &vec : prerequisites){
                int i = vec[0];
                int j = vec[1];
                ///j--->a
                adj[j].push_back(i);
                indegree[i]++;

            }
        int count = 0;
        queue<int> que;
        for(int v=0;v<numCourses;v++){
            if(indegree[v] == 0){
                que.push(v);
                count++;
            }
        }
        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(auto &v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    que.push(v);
                    count++;
                }
            }
        }
        if(count == numCourses) return true;
        return false;
    }
};