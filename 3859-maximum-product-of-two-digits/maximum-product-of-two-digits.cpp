class Solution {
public:
    int maxProduct(int n) {
        int maxVal = n % 10;
        int secMax = -1;
        n /= 10;
        
        while (n > 0) {
            int digit = n % 10;
            if (digit < maxVal) {
                if (digit > secMax) {
                    secMax = digit;
                }
            } else if (digit == maxVal) {
                secMax = maxVal;
            } else {
                secMax = maxVal;
                maxVal = digit;
            }
            n /= 10;
        }
        return maxVal * secMax;
    }
};