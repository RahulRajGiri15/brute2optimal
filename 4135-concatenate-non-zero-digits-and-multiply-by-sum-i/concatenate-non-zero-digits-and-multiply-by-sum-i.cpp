class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0,sum = 0,len = 1;
        while(n != 0){
            x = (n % 10) * len + x;
            if(n % 10 != 0) len = len * 10;
            sum += n % 10;
            n = n / 10;
        }
        return sum * x; 
    }
};