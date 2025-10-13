class Solution {
public:
    int n ;
    /////////////1
    // bool anagrm(string s , string r){
    //     sort(begin(s),end(s));
    //     sort(begin(r),end(r));
    //     if(s == r){
    //         return true;
    //     }
    //     return false;
    // }
    ////////////2
     bool anagrm(string s , string r){
        vector<int>check(26,0);
        for(int i=0;i<s.size();i++){
            check[s[i]-'a']++;
        }
        for(int i=0;i<r.size();i++){
            check[r[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(check[i] != 0){
                return false;
            }
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>result;
        result.push_back(words[0]);
        n = words.size();
        for(int i=1;i<n;i++){
            if(anagrm(words[i],result.back()) == false){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};