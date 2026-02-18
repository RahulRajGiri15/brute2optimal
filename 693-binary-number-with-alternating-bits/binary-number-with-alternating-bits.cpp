class Solution {
public:
    bool hasAlternatingBits(int n) {
        int currbit = n % 2;
        int nm = n/2 ;
        while(nm > 0){
            if(currbit == nm %2){
                return false;
            }
            currbit = nm % 2;
            nm = nm /2;
        }
        return true;
    }
};