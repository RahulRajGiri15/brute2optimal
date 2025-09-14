// class Solution {
// public:
//     unordered_set<string>exactset;
//     unordered_map<string,string>casemp;
//     unordered_map<string,string>vowelmp;

//     string tolowerr(string s){
//         string r ="";
//         for(char &c : s){
//             r.push_back(tolower(c));
//         }
//         return r;
//     }
//     string tovowel(string s){
//         string r ="";
//         for(char &c : s){
//             if(c == 'a'|| c == 'e'|| c == 'i'|| c == 'o'|| c == 'u'){
//                 c = '*';
//                 r.push_back(c);
//             }
//             else{
//                 r.push_back(c);
//             }
            
//         }
//         return r;
//     }
//     string checkforpri(string query){
//         if(exactset.count(query)){
//             return query;
//         }
//         string lowercase = tolowerr(query);
//         if(casemp.count(lowercase)){
//             return casemp[lowercase];
//         }
//         string vowelcase = tovowel(lowercase);
//         if(vowelmp.count(vowelcase)){
//             return vowelmp[vowelcase];
//         }
//         return "";
//     }


//     vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
//         exactset.clear();
//         casemp.clear();
//         vowelmp.clear();

//         for(auto word : wordlist){
//             ///filling in set
//             exactset.insert(word);
//             string lowercase = tolowerr(word);
//             ///filling in map
//             if(casemp.find(lowercase) == casemp.end()){
//                 casemp[lowercase] = word;
//             }
//             ////filling in vowel
//             string vowelcase = tovowel(lowercase);
//             if(vowelmp.find(vowelcase) == vowelmp.end()){
//                 vowelmp[vowelcase] = word;
//             }
//         }
//         vector<string>result;
//         for(auto &query : queries){
//             result.push_back(checkforpri(query));
//         }
//         return result;
//     }
// };

/////////////////////or

class Solution {
public:
    unordered_set<string>exactset;
    unordered_map<string,string>casemp;
    unordered_map<string,string>vowelmp;

    string tolowerr(string s){
        string result = s;
        for(char &c : result){
            c = tolower(c);
        }
        return result;
    }
    string tovowel(string s){
        string result = s;
        for(char &c : result){
            if(c == 'a'|| c == 'e'|| c == 'i'|| c == 'o'|| c == 'u'){
                c = '*';
                
            }
        }
        return result;
    }
    string checkforpri(string query){
        if(exactset.count(query)){
            return query;
        }
        string lowercase = tolowerr(query);
        if(casemp.count(lowercase)){
            return casemp[lowercase];
        }
        string vowelcase = tovowel(lowercase);
        if(vowelmp.count(vowelcase)){
            return vowelmp[vowelcase];
        }
        return "";
    }


    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactset.clear();
        casemp.clear();
        vowelmp.clear();

        for(auto word : wordlist){
            ///filling in set
            exactset.insert(word);
            string lowercase = tolowerr(word);
            ///filling in map
            if(casemp.find(lowercase) == casemp.end()){
                casemp[lowercase] = word;
            }
            ////filling in vowel
            string vowelcase = tovowel(lowercase);
            if(vowelmp.find(vowelcase) == vowelmp.end()){
                vowelmp[vowelcase] = word;
            }
        }
        vector<string>result;
        for(auto &query : queries){
            result.push_back(checkforpri(query));
        }
        return result;
    }
};