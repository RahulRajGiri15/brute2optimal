///////using stack

// class Solution {
// public:
//     string removesubstr(string &s , string &matchstr){
//         stack<char>st;
//         for(char &ch : s){
//             if(ch == matchstr[1] && !st.empty() && st.top() == matchstr[0]){
//                 st.pop();
//             }
//             else{
//                 st.push(ch);
//             }
//         }
//         string temp;
//         while(!st.empty()){
//             temp.push_back(st.top());
//             st.pop();
//         }
//         reverse(temp.begin(),temp.end());
//         return temp;
//     }
//     int maximumGain(string s, int x, int y) {
//         int n = s.length();
//         int score = 0;
        
//         string maxstr = (x > y)? "ab" : "ba";
//         string minstr = (x < y)? "ab" : "ba";

//         /////First pass
//         string temp_first = removesubstr(s,maxstr);
//         int L = temp_first.length();
//         int charremoved = (n - L);
//         score += (charremoved/2) * max(x,y);

//         //////Second pass
//         string temp_second = removesubstr(temp_first,minstr);
//         charremoved = (L - temp_second.length());

//         score += (charremoved/2) * min(x,y);

//         return score;
//     }
// };

//////////////////without using stack -- string and two pointer 
///how to delete a substring in o(1) space

// class Solution {
// public:
//     string removesubstr(string &s , string &matchstr){
//         int i=0; /// for writing only
//         for(int j=0;j<s.size();j++){
//             s[i] = s[j];
//             i++;
//             if(i>=2 && s[i-2] == matchstr[0] && s[i-1] == matchstr[1]){
//                 i = i-2;
//             }
//         }
//         s.erase(begin(s)+i,end(s));
//         return s;
//     }
//     int maximumGain(string s, int x, int y) {
//         int n = s.length();
//         int score = 0;
        
//         string maxstr = (x > y)? "ab" : "ba";
//         string minstr = (x < y)? "ab" : "ba";

//         /////First pass
//         string temp_first = removesubstr(s,maxstr);
//         int L = temp_first.length();
//         int charremoved = (n - L);
//         score += (charremoved/2) * max(x,y);

//         //////Second pass
//         string temp_second = removesubstr(temp_first,minstr);
//         charremoved = (L - temp_second.length());

//         score += (charremoved/2) * min(x,y);

//         return score;
//     }
// };

///////////////soltution 

class Solution {
public:
    string removesubstr(string &s, string &matchstr, int &gain, int score_per_match) {
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            s[i] = s[j];
            i++;

            if (i >= 2 && s[i - 2] == matchstr[0] && s[i - 1] == matchstr[1]) {
                i -= 2;  // remove last two characters
                gain += score_per_match;
            }
        }
        s.erase(begin(s) + i, end(s));
        return s;
    }

    int maximumGain(string s, int x, int y) {
        int score = 0;
        string maxstr = (x >= y) ? "ab" : "ba";
        string minstr = (x >= y) ? "ba" : "ab";
        int max_gain = max(x, y);
        int min_gain = min(x, y);

        int gain = 0;

        // First remove the max gain substring
        string temp = removesubstr(s, maxstr, gain, max_gain);
        // Then remove the other
        removesubstr(temp, minstr, gain, min_gain);

        return gain;
    }
};
