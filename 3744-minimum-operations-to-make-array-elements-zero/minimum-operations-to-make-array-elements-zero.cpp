////////////method 1 

// class Solution {
// public:
//     long long minOperations(vector<vector<int>>& queries) {
        
//         long long  result = 0;
//         for(auto &num : queries){
//             long long s = 1;
//             int l = num[0] , r = num[1];
//             long long L = 1, R = 1;
//             long long  start = 0 , end =0;
//             long long steps = 0;
            
//             while(L <= r){ /// compelete steps finding for 1 query
//                 R = 4 * L -1;
               
//                 start = max((long long) l,L);
//                 end = min((long long) r,R);
//                 if(start <= end){
//                     steps += (end-start+1)*s;
//                 }
//                 s +=1;
//                 L = L*4;
//             }
//             result += (steps+1)/2;
//         }
//         return result;
//     }
// };

///////////////////////method 2

class Solution {
public:
    long long solve(int l , int r){
        long long L = 1;
        long long R = 1;
        long long steps = 0;
        int s = 1;
        while(L <= r){
            R = 4*L -1;
            long long start = max((long long)l ,L);
            long long end = min((long long)r, R);
            if(start <= end){
                steps += (end - start +1)*s;
            }
            s += 1;
            L *= 4;
        }
        return steps;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;
        for(auto &query : queries){
            int l = query[0];
            int r = query[1];

            long long steps = solve(l,r);
            result += (steps+1)/2;
        }
        return result;
    }
};