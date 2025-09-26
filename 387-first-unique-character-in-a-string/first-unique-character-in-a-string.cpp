class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        int n = s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]  == 1){
                return i;
                break;
            }
        }
        return -1;
    }
};