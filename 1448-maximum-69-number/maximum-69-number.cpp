// class Solution {
// public:
//     int maximum69Number (int num) {
//         string ans = to_string(num);
//         for(int i=0;i<ans.size();i++){
//             if(ans[i] == '6'){
//                 ans[i] = '9';
//                 break;
//             }
//         }
//         // int res = stoi(ans);
//         // return res;
//         ////////////////////////
//         return stoi(ans);
//     }
// };

//////////////////////

class Solution {
public:
    int maximum69Number (int num) {
        int no = num;
        int pv = -1;
        int cnt = 0;
        while(num > 0){
            int r = num % 10;
            num = num / 10;
            if(r == 6){
                pv = cnt;
            }
            cnt++;
        }
        if(pv == -1) return no;
        no = no + (3* pow(10,pv));
        return no;
    }
};