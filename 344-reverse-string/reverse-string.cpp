class Solution {
public:
    void reverseString(vector<char>& s) {
        // vector<char> s2;
        // int n = s.size();
        // for(int i=n-1;i>=0;i--){
        //     s2.push_back(s[i]);
        // }
        // for(int i=0;i<n;i++){
        //     s[i] = s2[i];
        // }
        ////////////////////
        reverse(begin(s),end(s));

    }
};