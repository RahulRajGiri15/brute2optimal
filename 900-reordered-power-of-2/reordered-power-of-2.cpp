//////using string problem -- string anagrams

// class Solution {
// public:
//     string getsorted(int n){
//         string s = to_string(n); ///d-digits -- d = 10
//         sort(s.begin(),s.end()); ///d-digits o(dlogd)--o(10)
//         return s;
//     }
//     bool reorderedPowerOf2(int n) {
//         string ans = getsorted(n);
//         for(int p=0;p<30;p++){
//             if(ans == getsorted(1 << p)){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

////t--o(1)
////s---O(d)


///////////

class Solution {
public:
    bool reorderedPowerOf2(int n) {
       unordered_set<string>st;
       for(int p=0;p<=30;p++){
        string poww = to_string(1 << p);
        sort(begin(poww),end(poww));
        st.insert(poww);
       }
       string s = to_string(n);
       sort(begin(s),end(s));
       if(!st.count(s)){
        return false;
       }
       return true;
    }
};