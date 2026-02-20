class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string st = strs[i];
            sort(begin(st) , end(st));
            mp[st].push_back(strs[i]);
        }
        for(auto &it : mp){
            result.push_back(it.second);
        }
        return result;
    }
};