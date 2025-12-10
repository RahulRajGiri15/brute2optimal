class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(s[i] != ' '){
                temp += s[i];
            }
            else{
                if(!temp.empty()){
                    words.push_back(temp);
                    temp = "";
                }
            }
        }
        if(!temp.empty()){
            words.push_back(temp); ///push last word in temp
        }
        reverse(words.begin(),words.end());
        string result = "";
        for(auto &word : words){
            result += word;
            result += " ";
        }
        result.pop_back();
        return result;
    }
};