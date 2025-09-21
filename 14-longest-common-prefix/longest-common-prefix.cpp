class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        ////////take  first word in strs as base and solve the rest of the question
        string prefix = strs[0];
        for(int i=1;i<strs.size();i++){
            int j = 0;
            while(j < strs[i].size() && j < prefix.size() && prefix[j] == strs[i][j]){
                j++;
            }
            prefix = prefix.substr(0,j);
            if(prefix =="") return "";
        }
        return prefix;
    }
};