// class Solution {
// public:
//     int canBeTypedWords(string text, string brokenLetters) {
//         vector<string>st;
//         string r =""; 
//         for(auto c : text){
//             if(c == ' '){
//                 st.push_back(r);
//                 r = "";
//                 continue;
//             }
//             r.push_back(c);
//         }
//         st.push_back(r);
        
//         int count =0;
//         for(auto &it : st){
//             bool canform = true;
//             for(auto c : brokenLetters){
//                 for(char wc : it){
//                     if(c == wc){
//                         canform = false;
//                         break;
//                     }
//                 }
//             }
//             if(canform == true){
//                 count++;
//             }
//         }
//         return count;
//     }
// };

//////////////////////////////most optimal Solution 

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool mp[26];
        for(char &c : brokenLetters){
            mp[c-'a'] = true;
        }
        bool cantype = true;
        int result =0;
        for(char &ch : text){
            if(ch == ' '){ //////first word finished
                if(cantype){
                    result++;
                }
                cantype = true;
            }
            else if(mp[ch-'a'] == true){
                cantype = false;
            }
        }
        if(cantype){
            result++;
        }
        return result;
    }
};
