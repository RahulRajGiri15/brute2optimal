///////Brute force -- TLE

// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n == 1) return true;
//         if(n % 2 != 0) return false;

//         for(int i=1;i<=n/2;i++){
//             if(pow(2,i) == n){
//                 return true;
//                 break;
//             }
//         }
//         return false;
//     }
// };

//////t--o(n/2)
//////s--o(1)

////////// method 2 -- store all the power of 2 till INT_MAX

// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         vector<int>power;
//         long long v = 1;
//         while(v < INT_MAX){
//             power.push_back(int(v));
//             v *= 2;
//         }
//         return find(power.begin(),power.end(),n) != power.end();
//     }
// };

///t--o(1)
///s--o(1)---as 2^32 almost equals INT_MAX

////////////recursion 

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        if(n %2 != 0) return false;
        return isPowerOfTwo(n/2);
    }
};



//////////// bit wise 

// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n == 1) return true;
//         if(n > 0 && n%2 == 0){
//             return (n & (n-1)) == 0;
//         }
//         return false;
//     }
// };

////////or 


// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n > 0){
//             return (n & (n-1)) == 0;
//         }
//         return false;
//     }
// };

///t--o(1)
///s--o(1)