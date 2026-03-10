// class Solution {
// public:
//     int M = 1e9 + 7 ;

//     int solve(int zeroleft , int oneleft , bool lastwasone , int limit){
//         if(zeroleft == 0 && oneleft == 0){
//             return 1;
//         }
//         int result = 0;
//         if(lastwasone == true){ // explore 0
//             for(int len = 1; len <= min(zeroleft , limit) ; len++){
//                 result = (result + solve(zeroleft - len , oneleft, false, limit))% M;
//             }
//         }
//         else{ // explore 1 
//             for(int len = 1; len <= min(oneleft , limit); len++){
//                 result = (result + solve(zeroleft , oneleft - len , true , limit)) % M;
//             }
//         }
//         return result;
//     }
//     int numberOfStableArrays(int zero, int one, int limit) {
//         int startwithone = solve(zero , one , false, limit);
//         int startwithzero = solve(zero , one , true, limit);
//         return (startwithone + startwithzero) % M;
//     }
// };

////////////////////

// class Solution {
// public:
//     int M = 1e9 + 7 ;
//     int t[zero+1][one+1][2];

//     int numberOfStableArrays(int zero, int one, int limit) {

//        vector<vector<vector<int>>> t(zero +1 , vector<vector<int>>(one+1 , vector<int>(2,0)));

//         for(int i=0; i<= min(zero , limit); i++)
//             t[i][0][0] = 1;
//         for(int j=0; j<= min(one,limit); j++){
//             t[0][j][1] = 1;
//         }

//        for(int i=0;i<=zero ; i++){
//         for(int j=0;j<=one; j++){
//             if(i==0 && j == 0){
//                 continue;
//             }
//             if(j > 0)
//     t[i][j][1] = (t[i][j-1][0] + t[i][j-1][1]) % M;
//             if(j-1 >= limit) {
//                 if(j > 0)
//                     t[i][j][1] = (t[i][j-1][0] + t[i][j-1][1]) % M;
//             }
//             t[i][j][0] = (t[i-1][j][0] + t[i-1][j][1]) % M;
//             if(i-1 >= limit){
//                 if(i > 0)
//                     t[i][j][0] = (t[i-1][j][0] + t[i-1][j][1]) % M;
//             }
//         }
//        }
//        return (t[zero][one][0] + t[zero][one][1]) % M;
        
//     }
// };


class Solution {
public:
    int M = 1e9+7;
    int numberOfStableArrays(int zero, int one, int limit) {
        //t[zero+1][one+1][2] 
        vector<vector<vector<int>>> t(zero+1, vector<vector<int>>(one+1, vector<int>(2, 0)));

        for(int i = 0; i <= min(zero, limit); i++)
            t[i][0][0] = 1;
        
        for(int j = 0; j <= min(one, limit); j++) {
            t[0][j][1] = 1;
        }

        for(int i = 0; i <= zero; i++) { //i = # 0s
            for(int j = 0; j <= one; j++) { //j = # 1s

                if(i == 0 || j == 0)
                    continue;

                t[i][j][1] = (t[i][j-1][0] + t[i][j-1][1]) % M;
                
                if(j-1 >= limit) {
                    t[i][j][1] = (t[i][j][1] - t[i][j-1-limit][0] + M) % M;
                }

                t[i][j][0] = (t[i-1][j][0] + t[i-1][j][1]) % M;
                
                if(i-1 >= limit) {
                    t[i][j][0] = (t[i][j][0] - t[i-1-limit][j][1] + M) % M;
                }
            }
        }

        return (t[zero][one][0] + t[zero][one][1]) % M;
    }
};


