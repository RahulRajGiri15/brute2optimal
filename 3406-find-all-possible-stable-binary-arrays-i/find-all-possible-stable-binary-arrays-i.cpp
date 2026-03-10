// class Solution {
// public:
//     int M = 1e9 + 7;
//     int solve (int zeroleft , int oneleft , bool lastwasone , int limit){
//         if(oneleft == 0 && zeroleft == 0){
//             return 1;
//         }
//         int result = 0;
//         if(lastwasone == true){ // explore 0
//             for(int len=1;len <= min(zeroleft, limit); len++){
//                 result = (result + solve(zeroleft - len , oneleft , false , limit));
//             }
//         }
//         else{ // explore 1
//             for(int len=1;len <= min(oneleft, limit); len++){
//                 result = (result + solve(zeroleft , oneleft - len , true , limit));
//             }
//         }
//         return result;
//     }
//     int numberOfStableArrays(int zero, int one, int limit) {
//         int startwithone = solve(zero , one , false , limit);
//         int startwithzero = solve(zero , one , true, limit);
//         return (startwithone + startwithzero) % M;
//     }
// };


///////////////


// class Solution {
// public:
//     int M = 1e9 + 7;
//     int t[201][201][2];
//     int solve (int zeroleft , int oneleft , bool lastwasone , int limit){
//         if(oneleft == 0 && zeroleft == 0){
//             return 1;
//         }
//         if(t[zeroleft][oneleft][lastwasone] != -1){
//             return t[zeroleft][oneleft][lastwasone];
//         }

//         int result = 0;
//         if(lastwasone == true){ // explore 0
//             for(int len=1;len <= min(zeroleft, limit); len++){
//                 result = (result + solve(zeroleft - len , oneleft , false , limit)) % M;
//             }
//         }
//         else{ // explore 1
//             for(int len=1;len <= min(oneleft, limit); len++){
//                 result = (result + solve(zeroleft , oneleft - len , true , limit)) % M;
//             }
//         }
//         return t[zeroleft][oneleft][lastwasone] = result;
//     }
//     int numberOfStableArrays(int zero, int one, int limit) {
//         memset(t , -1 , sizeof(t));
//         int startwithone = solve(zero , one , false , limit);
//         int startwithzero = solve(zero , one , true, limit);
//         return (startwithone + startwithzero) % M;
//     }
// };


// /////////////



class Solution {
public:
    int M = 1e9 + 7 ;
    int t[201][201][2];

    int numberOfStableArrays(int zero, int one, int limit) {

        memset(t , 0 , sizeof(t));
        t[0][0][1] = 1;
        t[0][0][0] = 1;
        
        for(int oneleft = 0; oneleft <= one ; oneleft++){
            for(int zeroleft = 0; zeroleft <= zero; zeroleft++){

                if(zeroleft == 0 && oneleft == 0) continue;

                int result = 0;
                for(int len = 1; len <= min(zeroleft , limit); len++){
                    result = (result + t[zeroleft - len][oneleft][1]) % M;
                }
                t[zeroleft][oneleft][0] = result;

                result = 0;
                for(int len = 1; len <= min(oneleft , limit); len++){
                    result = (result + t[zeroleft][oneleft - len][0]) % M;
                }
                t[zeroleft][oneleft][1] = result;
            }
        }
        int startwithone = t[zero][one][0];
        int startwithzero = t[zero][one][1];
        return (startwithone + startwithzero) % M;
    }
};