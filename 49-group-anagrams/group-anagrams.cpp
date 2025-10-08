class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n = strs.size();
        unordered_map<string,vector<string>>mp;
        
        for(int i=0;i<n;i++){
            string st = strs[i];
            sort(st.begin(),st.end());
            
            mp[st].push_back(strs[i]);
        }
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};