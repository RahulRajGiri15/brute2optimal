class Solution {
public:
    bool anagrm(string s , string r){
        sort(begin(s),end(s));
        sort(begin(r),end(r));
        if(s == r){
            return true;
        }
        return false;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>result;
        result.push_back(words[0]);
        int n = words.size();
        for(int i=1;i<n;i++){
            if(anagrm(words[i],result.back()) == false){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};