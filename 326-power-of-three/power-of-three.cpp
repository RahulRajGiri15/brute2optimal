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

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n){
            if(n == 1){
                return true;
            }
            if(n % 3 == 0){
                n = n/3;
            }
            else{
                return false;
            }
        }
       return false;
    }
};


////////////

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

/////////// recursion -1 

// class Solution {
// public:
//     bool solve(int i ,int  n){
//         long long  val =1;
//         for(int j=1;j<i;j++){
//             val = val*3;
//         }
//         if(val == n){
//             return true;
//         }
//         if(val > n){
//             return false;
//         }
//         return solve(i+1,n);
//     }
//     bool isPowerOfThree(int n) {
//         if(n <= 0) return false;
//         return solve(1,n);
//     }
// };

////t--o(log n)
////s--o(log n)

//////////////// recursion - 2


// class Solution {
// public:
//     bool solve(long long val ,int  n){
//         if(val == n) return true;
//         if(val > n ) return false;
        
//         return solve(val * 3 , n);
//     }
//     bool isPowerOfThree(int n) {
//         return solve(1,n);
//     }
// };

////////////// other approach other than recursion and loop


// class Solution {
// public:
//     bool solve(long long val ,int  n){
//         if(val == n) return true;
//         if(val > n ) return false;
        
//         return solve(val * 3 , n);
//     }
//     bool isPowerOfThree(int n) {
//         return solve(1,n);
//     }
// };
