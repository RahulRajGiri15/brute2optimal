///Brute force -- using loop

// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         for(int i=0;i<=n;i++){
//             if(pow(3,i) == n){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

////t--o(n)
////s--o(1)

////////

// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//          if(n < 0) return false;
//         for(int i=0;i<=n/2;i++){
//             if(pow(3,i) == n){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

///t--o(n/2)
///s--o(1)

///////////wrong -- for large not work and pow return doubles

// class Solution {
// public:
//     bool solve(int i ,int  n){
        
//         if((pow(3,i)) == n){
//             return true;
//         }
//         if((pow(3,i)) > n){
//             return false;
//         }
//         return solve(i+1,n);
//     }
//     bool isPowerOfThree(int n) {
//         return solve(0,n);
//     }
// };

////////////////


class Solution {
public:
    bool solve(long long val ,int  n){
        if(val == n) return true;
        if(val > n ) return false;
        
        return solve(val * 3 , n);
    }
    bool isPowerOfThree(int n) {
        return solve(1,n);
    }
};