class Solution {
public:
    int reverseDegree(string s) {
        int  sum =0;
        for(int i=0;i<s.size();i++){
            int st = 26 - (s[i]-'a');
            int idx = i+1;
            sum += st*idx;
        }
        return sum;
    }
};