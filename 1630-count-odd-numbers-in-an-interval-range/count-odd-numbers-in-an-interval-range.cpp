// class Solution {
// public:
//     int countOdds(int low, int high) {
//         int count = 0;
//         for(int i=low;i<= high;i++){
//             if(i % 2 != 0) count++;
//         }
//         return count;
//     }
// };

///////////////////////

class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        if(low == high){
            count += low%2 != 0?1:0;
            return count;
        }
        if(low %2 != 0) count++;
        if(high %2 != 0) count++;
        int midnum = high - low - 1;

        if(count == 0) count += midnum/2 +1;
        else if(count == 1) count += midnum/2;
        else if(count == 2) count += midnum/2;

        return count;
    }
};

