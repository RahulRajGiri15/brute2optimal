// class Solution {
// public:
//     bool isbalanced(int num){
//         vector<int>count(10,0);
//         while(num >0){
//             int d = num % 10;
//             count[d]++;
//             num = num / 10;
//         }
//         for(int i=0;i<10;i++){
//             if(count[i] != 0 && count[i] != i){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int nextBeautifulNumber(int n) {
//         int maxx = pow(10,7);
//         for(int i = n+1 ; i<maxx ;i++){
//             if(isbalanced(i)){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

//////////////////////////////////////

////if the n = 10^6 than the maximum perfect number one can get is 1224444

class Solution {
public:
    bool isbalanced(int num){
        vector<int>count(10,0);
        while(num >0){
            int d = num % 10;
            count[d]++;
            num = num / 10;
        }
        for(int i=0;i<10;i++){
            if(count[i] != 0 && count[i] != i){
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        //int maxx = pow(10,7);
        for(int i = n+1 ; i<=1224444 ;i++){
            if(isbalanced(i)){
                return i;
            }
        }
        return -1;
    }
};