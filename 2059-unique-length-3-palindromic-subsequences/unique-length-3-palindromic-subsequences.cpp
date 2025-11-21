class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            st.insert(s[i]);
        }
        int res = 0;
        for(char letter : st){
            int first = -1;
            int last = -1;
            for(int i=0;i<n;i++){
                if(s[i] == letter){
                    if(first == -1){
                        first = i;
                    }
                    last = i;
                }
            }
            unordered_set<char>unqst;
            for(int k=first+1;k<=last-1;k++){
                unqst.insert(s[k]);
            }
            res += unqst.size();
        }
        return res;
    }
};