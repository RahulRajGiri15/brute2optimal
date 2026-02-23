class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int count = pow(2,k);
        unordered_set<string>st;
        for(int i=k;i<=n;i++){
            string sb = s.substr(i-k,k);
            if(st.count(sb) == false){
                st.insert(sb);
                count--;
            }
            if(count == 0){
                return true;
            }
        }
        return false;
    }
};