public class Solution {
    public bool IsPalindrome(int x) {
        if(x<0) return false;
        int r , n = 0;
        int s = x;
        while(x>0){
            r = x %10;
            n = n*10 + r;
            x = x/10;
        }
        if(s == n){
            return true;
        }
        return false;
    }
}