class Solution {
public:
    bool doesAliceWin(string s) {

        auto lambda = [] (char ch){
            return string {"aeiou"}.find(ch) != string::npos;
        };
        return any_of(begin(s),end(s),lambda);
    }
};



/////////////////////////smart solution --c#

// public class Solution {

//     private bool isVowel(char c){
//         c = char.ToLower(c);
//         return (c == 'a' || c == 'e'||c == 'i' || c == 'o'|| c =='u');
//     }

//     public bool DoesAliceWin(string s) {
//         foreach(char c in s){
//             if(isVowel(c)){
//                 return true; /// if there is even 1 vowel than alice forcefully wins
//             }
//         }
//         return false;
//     }
// }


////////////wrong approach

// public class Solution {

//     private bool IsVowel(char c){
//         c = char.ToLower(c);
//         return (c == 'a' || c == 'e'||c == 'i' || c == 'o'|| c =='u');
//     }
//     private string candelete(string r, string s){
//         if(s.Contains(r)){
//            s =  s.Replace(r,"");
//         }
//         return s;
//     }
//     public bool DoesAliceWin(string s) {
//         string r = "";
//         bool isalice = true;
//         bool isbob = false; 
//         int cnt = 0;
//         foreach(char c in s){
            
//             if(IsVowel(c)){
//                 cnt++;
//             }
//             r +=c;
//             if(cnt %2 != 0 && isalice){
//                 s = candelete(r,s);
//                 r = "";
//                 cnt = 0;
//                 isalice = false;
//                 isbob = true;
//             }
//             else if((cnt %2 == 0 || cnt == 0) && isbob){
//                 s = candelete(r,s);
//                 r = "";
//                 cnt =0;
//                 isbob = false;
//                 isalice = true;
//             }
//         }
//         if(isalice == true && isbob == false){
//             return false;
//         }
     
//         else{
//             return true;
//         }
//     }
// }

/////////////////////////smart solution 

// public class Solution {

//     private bool isVowel(char c){
//         c = char.ToLower(c);
//         return (c == 'a' || c == 'e'||c == 'i' || c == 'o'|| c =='u');
//     }

//     public bool DoesAliceWin(string s) {
//         foreach(char c in s){
//             if(isVowel(c)){
//                 return true; /// if there is even 1 vowel than alice forcefully wins
//             }
//         }
//         return false;
//     }
// }

