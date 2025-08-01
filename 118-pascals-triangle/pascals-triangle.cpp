////Most Optimal Solution 

// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         int n = numRows;
//         vector<vector<int>>result;
//         for(int i=1;i<=n;i++){
//             vector<int>curres(i);
//             curres[0] = 1;
//             curres[i-1] = 1;
//             for(int j=1;j<=i-2;j++){
//                 curres[j] = result[i-2][j-1] + result[i-2][j]; 
//                 ///i-2 will be there as we are starting from i = 1 so our first row is 
//                 ///i = 1 but actully the first row is starts form index 0
//             }
//             result.push_back(curres);
//         }
//         return result;
//     }
// };

///t-o(n^2)
///s-o(n^2)

/////////method 2 

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            vector<int>curres(i+1,1);
            for(int j=1;j<i;j++){
                curres[j] = result[i-1][j-1] + result[i-1][j]; 
            }
            result.push_back(curres);
        }
        return result;
    }
};