////////Recursion --- TLE

// class Solution {
// public:
//     vector<pair<int,int>> serving = {{100,0},{75,25},{50,50},{25,75}};
    
//     double solve(double A_left, double B_left){
//         if(A_left <= 0 && B_left<=0){
//             return 0.5;
//         }
//         if(A_left <= 0 ){
//             return 1;
//         }
//         if(B_left<=0){
//             return 0.0;
//         }
//         double probp = 0.0;
//         for(auto &p : serving){
//             int a = p.first;
//             int b = p.second;

//             probp += solve(A_left-a,B_left-b);
//         }
//         return 0.25 * probp;
//     }
//     double soupServings(int n) {
//         return solve(n,n);
//     }
// };


///////Memoization -- memory limit reached

// class Solution {
// public:
//     vector<pair<int,int>> serving = {{100,0},{75,25},{50,50},{25,75}};
//     vector<vector<double>> t;
//     double solve(double A_left, double B_left){
//         if(A_left <= 0 && B_left<=0){
//             return 0.5;
//         }
//         if(A_left <= 0 ){
//             return 1;
//         }
//         if(B_left<=0){
//             return 0.0;
//         }
//         if(t[A_left][B_left] != -1){
//             return t[A_left][B_left];
//         }
//         double probp = 0.0;
//         for(auto &p : serving){
//             int a = p.first;
//             int b = p.second;

//             probp += solve(A_left-a,B_left-b);
//         }
//         return t[A_left][B_left] = 0.25 * probp;
//     }
//     double soupServings(int n) {
//         t.resize(n+1,vector<double>(n+1,-1.0));
//         return solve(n,n);
//     }
// };

////t--o(n^2) --solution fails -- as Constraints: 0 <= n <= 109


////////Memoization --
/////for large value of n A probalilty is close to 1 

class Solution {
public:
    vector<pair<int,int>> serving = {{100,0},{75,25},{50,50},{25,75}};
    vector<vector<double>> t;
    double solve(double A_left, double B_left){
        if(A_left <= 0 && B_left<=0){
            return 0.5;
        }
        if(A_left <= 0 ){
            return 1;
        }
        if(B_left<=0){
            return 0.0;
        }
        if(t[A_left][B_left] != -1){
            return t[A_left][B_left];
        }
        double probp = 0.0;
        for(auto &p : serving){
            int a = p.first;
            int b = p.second;

            probp += solve(A_left-a,B_left-b);
        }
        return t[A_left][B_left] = 0.25 * probp;
    }
    double soupServings(int n) {
            ////as A looses more than B 
            /// than as n increases than probality of A looses all increases 
            ///// A will most likely drain first we 
            ////for large value of n A probalilty is close to 1
        if(n > 6000){ 
            return 1.0;
        }
        t.resize(n+1,vector<double>(n+1,-1.0));
        return solve(n,n);
    }
};