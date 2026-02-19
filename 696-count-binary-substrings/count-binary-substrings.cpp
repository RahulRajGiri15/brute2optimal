class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0;
        int prevcnt = 0;
        int currcnt = 1;
        for(int i=1;i<s.length();i++){
            if(s[i] == s[i-1]){
                currcnt++;
            }
            else{
                result += min(prevcnt , currcnt);
                prevcnt = currcnt;
                currcnt = 1;
            }
        }
        return result + min(prevcnt , currcnt);
    }
};