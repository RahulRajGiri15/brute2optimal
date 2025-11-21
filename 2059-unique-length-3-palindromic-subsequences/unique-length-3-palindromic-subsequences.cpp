// class Solution {
// public:
//     int countPalindromicSubsequence(string s) {
//         unordered_set<char>st;
//         int n = s.size();
//         for(int i=0;i<n;i++){
//             st.insert(s[i]);
//         }
//         int res = 0;
//         for(char letter : st){
//             int first = -1;
//             int last = -1;
//             for(int i=0;i<n;i++){
//                 if(s[i] == letter){
//                     if(first == -1){
//                         first = i;
//                     }
//                     last = i;
//                 }
//             }
//             unordered_set<char>unqst;
//             for(int k=first+1;k<=last-1;k++){
//                 unqst.insert(s[k]);
//             }
//             res += unqst.size();
//         }
//         return res;
//     }
// };

///////////////////////////////////

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<pair<int,int>>indices(26,{-1,-1});

        for(int i=0;i<n;i++){
            char ch = s[i];
            int idx = ch -'a';////a->0 , b->1
            if(indices[idx].first == -1){
                indices[idx].first = i;
            }
            indices[idx].second = i;
        }
        int res = 0;
        for(int i=0;i<26;i++){
            int first = indices[i].first;
            int last = indices[i].second;
            if(first == -1){
                continue; ////do index ny mile
            }

            unordered_set<char>unqst;
            for(int k=first+1;k<=last-1;k++){
                unqst.insert(s[k]);
            }
            res += unqst.size();
        }
        return res;
    }
};