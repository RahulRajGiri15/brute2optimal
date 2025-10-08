// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>>ans;
//         int n = strs.size();
//         unordered_map<string,vector<string>>mp;
        
//         for(int i=0;i<n;i++){   ///////o(n)
//             string st = strs[i];
//             sort(st.begin(),st.end()); //// o(klogk)
            
//             mp[st].push_back(strs[i]);
//         }
//         for(auto &it : mp){
//             ans.push_back(it.second);
//         }
//         return ans;
//     }
// };
////t--o(n*klogk)
////s--o(n*n)


///////////////////////////////////////

class Solution {
public:
    string generate(string word){
        vector<int>alp(26,0);
        for(char &c : word){
            alp[c-'a']++;
        }
        string ans = "";
        for(int i=0;i<26;i++){
            int freq = alp[i];
            if(freq > 0){
                ans += string(freq,i+'a');
            }
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n = strs.size();
        unordered_map<string,vector<string>>mp;
        
        for(int i=0;i<n;i++){   ///////o(n)
            string st = strs[i];

            string newword = generate(st);
            
            mp[newword].push_back(strs[i]);
        }
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
