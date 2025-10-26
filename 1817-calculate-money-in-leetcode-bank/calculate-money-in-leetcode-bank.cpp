// class Solution {
// public:
//     int totalMoney(int n) {
//         int i = 0;
//         int sum = 0;
//         int count = 0;
//         int week = 0;
//         if(n <= 7){
//             for(int i = 1;i<=n;i++){
//                 sum += i;
//             }
//         }

//         else if(n > 7){
//             while(count < n){
//                 for(int k=1; k<=7 && count < n; k++){
//                     /////every week is 1 + previous value
//                     sum += (k + week);
//                     count++;
//                 }
//                 week++;
//             }
//         }
//         return sum;
//     }
// };

////////////////////

// class Solution {
// public:
//     int totalMoney(int n) {
//         int result =0;
//         int week =0;
//         while(n > 0){
//             for(int i=1;i<= min(n,7);i++){
//                 result += i + week;
//             }
//             n = n-7;
//             week++;
//         }
//         return result;
//     }
// };

/////////////////////////////////using ap concept

// class Solution {
// public:
//     int totalMoney(int n) {
//         int result =0;
        
//         int totalweeks = n / 7;
//         int reminingdays = n % 7;

//         int firstel = 28; /// first week sum
//         int lastweekel = firstel +(totalweeks - 1) * 7;  /////// last = a + (n-1)*d

//         result = totalweeks * (firstel + lastweekel)/2; ////sum = n*(a1 + al)/2;

//         ///for remaining days 

//         int startel = 1 + totalweeks;
//         for(int i =1;i<= reminingdays;i++){
//             result += startel;
//             startel++;
//         }
//         return result;
//     }
// };

//////////////////////////

class Solution {
public:
    int totalMoney(int n) {
        int result =0;
        
        int totalweeks = n / 7;
        int reminingdays = n % 7;

        int firstel = 28; /// first week sum
        int lastweekel = firstel +(totalweeks - 1) * 7;  /////// last = a + (n-1)*d

        result = totalweeks * (firstel + lastweekel)/2; ////sum = n*(a1 + al)/2;

        ///for remaining days 

        int startel = 1 + totalweeks;
        int lastel = startel + (reminingdays - 1) * 1;
        result += reminingdays * (startel + lastel)/2;

        return result;
    }
};
