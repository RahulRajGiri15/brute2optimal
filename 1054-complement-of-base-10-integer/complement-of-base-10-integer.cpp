class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1; // as n ^ (1..1) = complement number
        if(n == 0) return 1;
        while(mask <= n){
            mask <<= 1;
        }
        return (mask -1) ^ n;
    }
};