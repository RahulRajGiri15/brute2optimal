// class Solution {
// public:
//     void FloydWarshall(vector<vector<long long>> &adjMatrix, vector<char> &original , vector<char> &changed , vector<int> &cost){
//         for(int i=0; i < original.size();i++){
//             int s = original[i] - 'a';
//             int t = changed[i] - 'a';
//             adjMatrix[s][t] = min(adjMatrix[s][t] , (long long)cost[i]);
//         }
//         // FloydWarshall 
//         for(int k = 0;k<26;++k){
//             for(int i=0;i<26;++i){
//                 for(int j=0;j<26;++j){
//                     adjMatrix[i][j] = min(adjMatrix[i][j] , adjMatrix[i][k]+adjMatrix[k][j]);
//                 }
//             }
//         }
//     }
//     long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         vector<vector<long long>> adjMatrix(26,vector<long long>(26 , INT_MAX));
//         FloydWarshall(adjMatrix , original , changed , cost);
//         long long ans = 0;

//         for(int i=0;i< source.length(); i++){
//             if(source[i] == target[i]){
//                 continue;
//             }
//             if(adjMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX){
//                 return -1;
//             }
//             ans += adjMatrix[source[i] -'a'][target[i] - 'a'];
//         }
//         return ans;
//     }
// };

// Dijistra algorithm 


class Solution {
public:
    void dijkstra(char &source ,unordered_map<char , vector<pair<char ,int>>> &adj, vector<vector<long long >> &costMatrix ){
        priority_queue<pair<int , char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
        pq.push({0,source});
        while(!pq.empty()){
            int d = pq.top().first;
            char adjNode = pq.top().second;
            pq.pop();
            for(auto &it : adj[adjNode]){
                char adjNode = it.first;
                int cost = it.second;

                if(costMatrix[source - 'a'] [ adjNode - 'a'] > d + cost){
                    costMatrix[source - 'a'][adjNode - 'a'] = d + cost;
                    pq.push({d + cost , adjNode});
                }
            }
        }
        return;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char , vector<pair<char ,int>>> adj;
        for(int i=0;i<original.size();i++){
            adj[original[i]].push_back({changed[i], cost[i]});
        }
        vector<vector<long long >> costMatrix(26, vector<long long>(26 , INT_MAX));
        // populate the costMatrix with dijkstra algorithm
        for(int i=0;i<source.size();i++){
            char ch = source[i];
            dijkstra(ch , adj, costMatrix);
        }
        long long ans = 0 ;
        for(int i=0; i< source.length();i++){
            if(source[i] == target[i]){
                continue;
            }
            if(costMatrix[source[i]-'a'][target[i] - 'a'] == INT_MAX){
                return -1;
            }
            ans += costMatrix[source[i]-'a'][target[i] - 'a'];
        }
        return ans;
    }
};