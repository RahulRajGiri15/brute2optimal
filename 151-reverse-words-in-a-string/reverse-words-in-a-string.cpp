class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int n = s.size();
        vector<string>st;
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                if(res.empty() == false){
                    st.push_back(res);
                    res = "";
                }
            }
            else{
                res.push_back(s[i]);
            }
        }
        if(!res.empty()){ //////push back last word
            st.push_back(res);
        }
        reverse(begin(st),end(st));

        string final = "";
        for(int i=0;i<st.size();i++){
            final +=st[i];
            if(i != st.size()-1){
                final += ' ';
            }
        }
        return final;
    }
};