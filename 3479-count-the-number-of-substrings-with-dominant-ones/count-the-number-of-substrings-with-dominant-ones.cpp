// class Solution {
// public:
//     int numberOfSubstrings(string s) {
        
//         int n = s.size();
//         int maincount =0;
//         for(int i=0;i<n;i++){
//             for(int j =0;j<=i;j++){
//                 int countzero = 0;
//                 int countone = 0;
//                 for(int k=j;k<=i;k++){
//                     if(s[k] == '0'){
//                         countzero++;
//                     }
//                     else if(s[k] == '1'){
//                         countone++;
//                     }
//                 }
//                 if(countone >= (countzero * countzero)){
//                     maincount++;
//                 }
//             }
//         }
//         return maincount;
//     }
// };

/////////////////////////////method 2 --- we find prefind the cumulative sum of the array


// class Solution {
// public:
//     int numberOfSubstrings(string s) {
        
//         int n = s.size();
//         int maincount = 0;
//         vector<int>one(n+1,0);
//         vector<int>zero(n+1,0);
//         for(int i=0;i<n;i++){
//             one[i+1] = one[i] + (s[i] == '1');
//             zero[i+1] = zero[i] + (s[i] == '0');
//         }

//         for(int i=0;i<n;i++){
//             int countone = 0;
//             int countzero = 0;
//             for(int j=i;j<n;j++){
//                countone = one[j+1] - one[i];
//                countzero = zero[j+1] - zero[i];
//                if(countone >= (countzero * countzero)){
//                 maincount++;
//                } 
//             }
//         }
//         return maincount;
//     }
// };


///////////////////////////////

class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.size();
        vector<int>cumsum(n,0);
        cumsum[0] = (s[0] == '1') ? 1 : 0;
        for(int i=1;i<n;i++){
            cumsum[i] = cumsum[i-1] + ((s[i] == '1') ? 1 : 0 );
        }

        ////i .... j
        int res = 0; ///main count 
        for(int i=0;i<n;i++){
            int countone = 0;
            int countzero = 0;
            for(int j=i;j<n;j++){
               countone = cumsum[j] - (i-1 >= 0 ? cumsum[i-1] : 0);
               countzero = (j-i + 1) - countone;

               if((countzero * countzero) > countone){
                //////skip unnessarsary index and increment j to right index
                int waste = (countzero * countzero) - countone;
                j += waste -1;
               } 
               else if((countzero * countzero) == countone){
                res += 1;
               }
               else{ //((countzero * countzero) < countone){
                res += 1;

                ////extra index till j can expand 
                int k = sqrt(countone) - countzero;
                int nextj = j + k;
                if(nextj >= n){ ///out of bound
                    res += n -j-1;
                    break; ///early break
                }
                else{///nextj < n
                    res += k;
                }
                j = nextj;

               }
            }
        }
        return res;
    }
};