// class Solution {
// public:
//     int solve(vector<pair<int,int>>& count,int m ,int n, int i){
//         if(i >= count.size() || (m==0 && n == 0)){
//             return 0;
//         }
//         int take = 0;
//         if(m >= count[i].first && n >= count[i].second){
//             take = 1 + solve(count ,m-count[i].first , n-count[i].second, i+1);
//         }
//         int skip = solve(count , m , n, i+1);
//         return max(skip,take);
//     }
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         int N = strs.size();
//         vector<pair<int,int>>count(N);
//         for(int i=0;i<N;i++){
//             int countzero =0;
//             int countone = 0;
//             for(const char &c :strs[i]){
//                 if(c == '0'){
//                     countzero++;
//                 }
//                 else{
//                     countone++;
//                 }
//             }
//             count[i]= {countzero,countone};
//         }
//         int res = solve(count , m , n , 0);
//         return res;
//     }
// };

///////////////////////////


class Solution {
public:
    int t[101][101][601];
    int solve(vector<pair<int,int>>& count,int m ,int n, int i){
        if(i >= count.size() || (m==0 && n == 0)){
            return 0;
        }
        if(t[m][n][i] != -1){
            return t[m][n][i];
        }
        int take = 0;
        if(m >= count[i].first && n >= count[i].second){
            take = 1 + solve(count ,m-count[i].first , n-count[i].second, i+1);
        }
        int skip = solve(count , m , n, i+1);
        return t[m][n][i] =  max(skip,take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<pair<int,int>>count(N);
        for(int i=0;i<N;i++){
            int countzero =0;
            int countone = 0;
            for(const char &c :strs[i]){
                if(c == '0'){
                    countzero++;
                }
                else{
                    countone++;
                }
            }
            count[i]= {countzero,countone};
        }
        memset(t,-1,sizeof(t));
        int res = solve(count , m , n , 0);
        return res;
    }
};