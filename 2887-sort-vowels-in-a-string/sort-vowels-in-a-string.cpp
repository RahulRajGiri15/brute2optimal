class Solution {
public:
     bool isVowel(char c){
        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c=='o' || c == 'u'){
            return true;
        }
        return false;
        }
    string sortVowels(string s) {
        string temp ;
        for(char &c : s){
            if(isVowel(c)){
                temp.push_back(c);
            }
        }
        sort(temp.begin(),temp.end());
        int k=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i] = temp[k];
                k++;
            }
        }
        return s;
    }
};
