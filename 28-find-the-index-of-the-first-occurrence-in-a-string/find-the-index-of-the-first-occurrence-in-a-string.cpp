// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         if(needle.size() == 0 || haystack.size() == 0)return -1;
//         int foundfrst = -1;
//         for(int i=0;i<=haystack.size()-needle.size();i++){
//             if(foundfrst != -1){
//                 break;
//             }
//             int k =i;
//             int j =0;
//             bool mila = true;
//             while(j<needle.size()){
//                 if(haystack[i+j] != needle[j]){
//                     mila = false;
//                     break;
//                 }
//                 j++;
//             }
//             if(mila == true && foundfrst == -1){
//                 foundfrst = k;
//             }
            
//         }
//         return foundfrst;
//     }
// };

//////////////////////////////


// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         if(needle.size() == 0 )return 0;
//         if(haystack.size() == 0) return -1;

//         for(int i=0;i<=haystack.size()-needle.size();i++){


//             int j =0;
           
//             while(j< needle.size() && haystack[i+j] == needle[j]){
//                 j++;
//             }
//             if(j == needle.size()) return i;

            
//         }
//         return -1;
//     }
// };

///////////

class Solution {
public:
    int strStr(string haystack, string needle) {
        int foundfrst = -1;
        for(int i=0;i<haystack.size();i++){
            int k =i;
            int j =0;
            bool mila = true;
            while(j<needle.size()){
                if(haystack[i+j] != needle[j]){
                    mila = false;
                    break;
                }
                j++;
            }
            if(mila == true && foundfrst == -1){
                foundfrst = k;
            }
        }
        return foundfrst;
    }
};