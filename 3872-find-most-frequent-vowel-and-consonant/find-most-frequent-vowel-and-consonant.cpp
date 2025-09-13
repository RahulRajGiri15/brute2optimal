class Solution {
public:
    bool isvowel(char c){
        c = tolower(c);
        return (c == 'a'|| c == 'e'|| c == 'i'|| c == 'o'|| c == 'u');
    }
    int maxFreqSum(string s) {
        unordered_map<char,int>vowel;
        unordered_map<char,int>consonant;
        for(char &c : s){
            if(isvowel(c)){
                vowel[c]++;
            }
            else{
                consonant[c]++;
            }
        }
        int maxvow = 0;
        int maxcos = 0;
        for(auto &it : vowel){
            if(it.second >maxvow){
                maxvow = it.second;
            }
        }
        for(auto &it : consonant){
            if(it.second >maxcos){
                maxcos = it.second;
            }
        }
        return maxcos+maxvow;
    }
};