class Solution {
public:
    vector<vector<int>> direction{{-1,0},{1,0},{0,1},{0,-1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>>que;
        int i=0 , j =0;
        que.push({0,0,k}); ///starting point 

        bool visited[41][41][1600];
        memset(visited,false,sizeof(visited));

        int steps = 0;
        /////start the BFS 
        while(!que.empty()){
            int size = que.size();
            while(size--){
                vector<int>temp = que.front();
                que.pop();
                
                int curr_i = temp[0];
                int curr_j = temp[1];
                int obs = temp[2];
                if(curr_i == m-1 && curr_j == n-1){ ///reaced finish line
                    return steps;
                }
                for(vector<int> &dir : direction){
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];
                    if(new_i <0 || new_i >= m || new_j < 0 || new_j >= n){
                        continue; /// out of bound 
                    }
                    if( grid[new_i][new_j] == 0 && !visited[new_i][new_j][obs]){
                        que.push({new_i,new_j,obs});
                        visited[new_i][new_j][obs] = true;
                    }
                    else if(grid[new_i][new_j] == 1 && obs >0 && !visited[new_i][new_j][obs-1]){
                        que.push({new_i,new_j,obs-1});
                        visited[new_i][new_j][obs-1] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};