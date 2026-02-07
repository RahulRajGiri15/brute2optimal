// class Solution {
// public:
//     bool checksame(vector<int> &freq){
//         int common = 0;
//         for(int i=0;i<26;i++){
//             if(freq[i] == 0) continue;
//             if(common == 0){
//                 common = freq[i];
//             }
//             else if(freq[i] != common){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int minimumDeletions(string s) {
//         int n = s.length();
//         int maxsz = 0;
//         for(int i=0;i<n;i++){
//             vector<int>freq(26,0);
//             for(int j=i;j<n;j++){
//                 freq[s[j] - 'a']++;
//                 if(checksame(freq)){
//                     maxsz = max(maxsz , j-i+1);
//                 }
//             }
//         }
//         return maxsz;
//     }
// };


class Solution {
public:
    int minimumDeletions(string s) {
        int n     = s.length();
        int count = 0;

        stack<char> st;

        for(int i = 0; i < n; i++) {
            if(!st.empty() && s[i] == 'a' && st.top() == 'b') { //'ba'
                st.pop();
                count++;
            } else {
                st.push(s[i]);
            }
        }

        return count;
    }
};
