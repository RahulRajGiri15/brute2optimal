class Solution {
public:
    bool isPalindrome(int x) {
        long long  p=0;
        int s =x;
        if(x < 0) return false;
        while(x != 0){
            int r = x%10;
            p = p*10+r;
            x = x/10;
        }
        if((int)p == s){
            return true;
        }
        return false;

    }
};