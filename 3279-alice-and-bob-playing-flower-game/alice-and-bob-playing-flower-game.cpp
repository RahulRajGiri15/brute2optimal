///////brute force

// class Solution {
// public:
//     long long flowerGame(int n, int m) {
//         long long cnt = 0;
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if((i+j)%2 != 0){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

/////////// best method
///the only case where alis win is when pair sum is odd 

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long cnt = 0;

        long long even_n = n/2;
        long long odd_n = (n+1)/2;
        long long even_m = m/2;
        long long odd_m = (m+1)/2;

        cnt = (even_n * odd_m) + (odd_n * even_m); 

        return cnt;
    }
};