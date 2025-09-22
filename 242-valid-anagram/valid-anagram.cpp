class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(auto &c : s){
            mp1[c]++;
        }
        for(auto &c : t){
            mp2[c]++;
        }
        int n1 = mp1.size();
        int n2 = mp2.size();
        if(n1 != n2){
            return false;
        }
        for(auto &it : mp1){
            if(mp2[it.first] != it.second){
                return false;
            }
        }
        
        return true;
    }
};