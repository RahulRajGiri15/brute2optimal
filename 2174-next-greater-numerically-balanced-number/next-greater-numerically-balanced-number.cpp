
class Solution {
public:
    vector<int>digitcount{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int backtrack(int n , int curr ,int count){
        if(count == 0){
            for(int i=1;i<=9;i++){
                if(digitcount[i] != 0 && digitcount[i] != i){
                    return 0;
                }
            }
            return curr > n ? curr : 0;
        }
        int result = 0;
        for(int i=1;i<=9;i++){
            if(digitcount[i] !=0 && digitcount[i] <= count){
                digitcount[i]--;
                result = backtrack(n , curr*10 + i, count -1);
                digitcount[i]++;
            }
            if(result != 0){
                break;
            }
        }
        return result;
    }
    int nextBeautifulNumber(int n) {
        int numdigit = to_string(n).size();
        int result = 0 ;
        result = backtrack(n,0,numdigit);
        if(result == 0){
            result = backtrack(n,0,numdigit +1);
        }
        return result;
    }
};

////////////////////////////////////////////////////////
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
//         //int maxx = pow(10,7);
//         for(int i = n+1 ; i<=1224444 ;i++){
//             if(isbalanced(i)){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };