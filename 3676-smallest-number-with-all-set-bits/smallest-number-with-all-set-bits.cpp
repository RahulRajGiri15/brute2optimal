class Solution {
public:
    bool checksetbits(int num){
        return (num & (num +1)) == 0; 
    }
    int smallestNumber(int n) {
        int result = n;
        while(checksetbits(result) == false){
            result++;
        }
        return result;
    }
};