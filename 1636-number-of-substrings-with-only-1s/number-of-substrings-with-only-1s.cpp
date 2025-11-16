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

////////////////////

class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        long long count = 0;
        const int M = 1e9 + 7;
        long long res = 0;
        for(int i=0;i<n;i++){ 
            if(s[i] == '1'){
                count++;
            }
            else{
                res += (count * (count +1)/2) % M;
                count = 0;
            }
        }
        res += (count * (count + 1) /2) % M;

        return int(res);
    }
};