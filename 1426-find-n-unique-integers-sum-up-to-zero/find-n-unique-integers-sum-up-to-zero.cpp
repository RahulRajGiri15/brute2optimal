/////////////method 1 -- 1st approach 

// class Solution {
// public:
//     vector<int> sumZero(int n) {
//         vector<int>res;
//         if(n %2 != 0){
//             n = n-1;
//             res.push_back(0);
//         }
//         for(int i=1;i<=n/2;i++){
//             res.push_back(i);
//             res.push_back(-i);
//         }
//         return res;
//     }
// };

//////////////method 2 -- 

// class Solution {
// public:
//     vector<int> sumZero(int n) {
//         vector<int>res(n);
//         int start = 1;
//         int i=0;
//         while(i+1 < n){
//             res[i] = start;
//             res[i+1] = -start;
//             i +=2;
//             start++;
//         }
//         return res;
//     }
// };

///////////// method 3 -- 

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>res(n);
        int start = 1;
        int i=0;
        int j = n-1;
        while(i < j){
            res[i] = start;
            res[j] = -start;
            i++;
            j--;
            start++;
        }
        return res;
    }
};