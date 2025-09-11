// class Solution {
// public:
//      bool isVowel(char c){
//         c = tolower(c);
//         if(c == 'a' || c == 'e' || c == 'i' || c=='o' || c == 'u'){
//             return true;
//         }
//         return false;
//         }
//     string sortVowels(string s) {
//         string temp ;
//         for(char &c : s){
//             if(isVowel(c)){
//                 temp.push_back(c);
//             }
//         }
//         sort(temp.begin(),temp.end());
//         int k=0;
//         for(int i=0;i<s.size();i++){
//             if(isVowel(s[i])){
//                 s[i] = temp[k];
//                 k++;
//             }
//         }
//         return s;
//     }
// };


///////////////////////


class Solution {
public:
     bool isVowel(char c){
        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c=='o' || c == 'u'){
            return true;
        }
        return false;
        }
    string sortVowels(string s) {
        unordered_map<char, int>mp;
        for(char &c : s){
            if(isVowel(c)){
                mp[c]++;
            }
        }
        string temp = "AEIOUaeiou";
        int j =0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                while(mp[temp[j]] == 0){
                    j++;
                }
                s[i] = temp[j];
                mp[temp[j]]--;
            }
        }
        return s;
    }
};







