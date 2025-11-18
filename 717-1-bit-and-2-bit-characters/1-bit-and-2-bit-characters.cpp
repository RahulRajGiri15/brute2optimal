// class Solution {
// public:
//     bool isOneBitCharacter(vector<int>& bits) {
//         int i =0;
//         int n = bits.size();
//         while(i < n-1){
//             i += (bits[i] == 1) ? 2 : 1;
//         }
//         return (i == n-1);
//     }
// };

//////////////////

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int count =0;
        for(int i=n-2; i>=0 && bits[i] == 1; i--){
            count++;
        }
        return (count % 2 == 0);//// in case of even count -- it is always true
    }
};