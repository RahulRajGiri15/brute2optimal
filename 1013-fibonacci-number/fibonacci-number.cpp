/////////using recursion 

class Solution {
public:
    int fib(int n) {
        ////base case
        if(n==0) return 0;
        if(n==1) return 1;

        ///////recursive code
        return fib(n-1)+fib(n-2);
    }
};