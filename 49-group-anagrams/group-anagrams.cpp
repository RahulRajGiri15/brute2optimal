// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> result;
//         unordered_map<string, vector<string>>mp;
//         for(int i=0;i<strs.size();i++){
//             string st = strs[i];
//             sort(begin(st) , end(st));
//             mp[st].push_back(strs[i]);
//         }
//         for(auto &it : mp){
//             result.push_back(it.second);
//         }
//         return result;
//     }
// };

// 

class Solution {
public:
    string makesort(string word){
        string ans = "";
        vector<int>freqw(26,0);
        for(char &ch : word){
            freqw[ch -'a']++;
        }
        for(int i=0;i<26;i++){
            if(freqw[i] > 0){
                ans +=string(freqw[i] , i + 'a');
            }
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string st = strs[i];
            string newword = makesort(st);
            mp[newword].push_back(strs[i]);
        }
        for(auto &it : mp){
            result.push_back(it.second);
        }
        return result;
    }
};

