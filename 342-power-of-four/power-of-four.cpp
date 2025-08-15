// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         ////highest power of 4 in INT_MAX is 4^15 = 1073741824
//         return n > 0 && (int)(pow(4,15)) % n == 0 ;
//     }
// };

/////////////

// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         ////highest power of 4 in INT_MAX is 4^15 = 1073741824
//         if(n == 2) return false;
//         return n > 0 && 1073741824 % n == 0 ;
//     }
// };

////////////////loop 

// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         long long val = 1;
//         if(n <= 0) return false;
//         for(int i=0;i<n;i++){
//             if(val == n){
//                 return true;
//             }
//             val = val*4;
//         }
//         return false;
//     }
// };

////////

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        while(n%4 == 0){
            n = n/4;
        }
        return n == 1;
    }
};