// class Solution {
// public:
//     bool checkOnesSegment(string s) {
//         int count = 1;
//         for(int i = 0; i<s.size() -1; i++){
//             if( s[i] == '0' && s[i+1] == '1'){
//                 count++;
//             }
//         }
//         if(count == 1){
//             return true;
//         }
//         return false;
//     }
// };


//////////////////

class Solution {
public:
    bool checkOnesSegment(string s) {
        int count = 1;
        for(int i = 0; i<s.size() -1; i++){
            if(s[i] == '0' && s[i+1] == '1'){
                return false;
            }
        }
        return true;
    }
};