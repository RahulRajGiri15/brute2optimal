/////Brute force

// class Solution {
// public:
//     string largestGoodInteger(string num) {
//         string res = "";
//         int cnt = 0;
//         for(int i=0;i<=num.size()-3;i++){
//             if(num[i] == num[i+1] && num[i+1] == num[i+2]){
//                 if(cnt == 0){
//                     res = string(3,num[i]);
//                     cnt++;
//                 }
//                 else if(cnt != 0){
//                     int temp = atoi(string(3,num[i]).c_str());
//                     if(atoi(res.c_str()) < temp){
//                         res = to_string(temp);
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };

///////////another method

// class Solution {
// public:
//     string largestGoodInteger(string num) {
//         string res = "";
//         for(int i=0;i<=num.size()-3;i++){
//             if(num[i] == num[i+1] && num[i+1] == num[i+2]){
//                 string curr = string(3,num[i]);
//                 res = max(res,curr);
//             }
//         }
//         return res;
//     }
// };

///////////////

// class Solution {
// public:
//     string largestGoodInteger(string num) {
//         string  res ="";
//         char maxchar = ' ';
//         for(int i=2;i<num.size();i++){
//             if(num[i] == num[i-1] && num[i] == num[i-2]){
//                 maxchar = max(maxchar,num[i]);
//             }
//         }
//         if(maxchar == ' '){
//             return res;
//         }
//         res = string(3,maxchar);
//         return res;
//     }
// };

//////////////


class Solution {
public:
    string largestGoodInteger(string num) {
        char maxchar = ' ';
        for(int i=2;i<num.size();i++){
            if(num[i] == num[i-1] && num[i] == num[i-2]){
                maxchar = max(maxchar,num[i]);
            }
        }
        if(maxchar == ' '){
            return "";
        }
        return  string(3,maxchar);
    }
};