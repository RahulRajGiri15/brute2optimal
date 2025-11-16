// class Solution {
// public:
//     int numSub(string s) {
//         int n = s.size();
//         int count = 0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<=i;j++){
//                 bool iszero = false;
//                 for(int k=j;k<=i;k++){
//                     if(s[k] !='1'){
//                         iszero = true;
//                         break; 
//                     }
//                 }
//                 if(iszero == false){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

////////////////////using formula 
/// (n * (n -1) / 2) -- n = no of 1 's in a substring 
///if n = 2 -- than 2 * 3 /2 = 3 --- that means 3 substring of 1 is possible with 2 -- 1's

// class Solution {
// public:
//     int numSub(string s) {
//         int n = s.size();
//         long long count = 0;
//         const int M = 1e9 + 7;
//         long long res = 0;
//         for(int i=0;i<n;i++){ 
//             if(s[i] == '1'){
//                 count++;
//             }
//             else{
//                 res += (count * (count +1)/2) % M;
//                 count = 0;
//             }
//         }
//         res += (count * (count + 1) /2) % M;

//         return int(res);
//     }
// };

/////////////////////most optimised approach ---- 

// class Solution {
// public:
//     int numSub(string s) {
//         int n = s.size();
//         long long count = 0;
//         const int M = 1e9 + 7;
//         long long res = 0;
//         for(int i=0;i<n;i++){ 
//             if(s[i] == '1'){
//                 count++;
//                 res += count;
//             }
//             else{
//                 count = 0;
//             }
//         }
//         return int(res);
//     }
// };

//////////////////////////

// class Solution {
// public:
//     int numSub(string s) {
//         int n = s.size();
//         const int M = 1e9 + 7;

//         long long count = 0;
//         long long res = 0;
//         for(int i=0;i<n;i++){ 
//             if(s[i] == '1'){
//                 count++;
//                 res = (res + count) % M;
//             }
//             else{
//                 count = 0;
//             }
//         }
//         return int(res);
//     }
// };

///////////////


class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        const int M = 1e9 + 7;

        int count = 0;
        int res = 0;
        for(int i=0;i<n;i++){ 
            if(s[i] == '1'){
                count++;
                res = (res + count) % M;
            }
            else{
                count = 0;
            }
        }
        return res;
    }
};