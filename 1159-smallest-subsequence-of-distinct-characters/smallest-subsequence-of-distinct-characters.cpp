class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> seen(26, false);
        
        for(char &x : s) {
            freq[x - 'a']++;
        }
        
        string res = "";
        for(char &x : s) {
            freq[x - 'a']--;
            
            if(seen[x - 'a']) continue;
            
            while(!res.empty() && res.back() > x && freq[res.back() - 'a'] > 0) {
                seen[res.back() - 'a'] = false;
                res.pop_back();
            }
            
            res += x;
            seen[x - 'a'] = true;
        }
        return res;
    }
};