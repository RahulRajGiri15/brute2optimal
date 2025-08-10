class Solution {
public:
    string getsorted(int n){
        string s = to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string ans = getsorted(n);
        for(int p=0;p<30;p++){
            if(ans == getsorted(1 << p)){
                return true;
            }
        }
        return false;
    }
};