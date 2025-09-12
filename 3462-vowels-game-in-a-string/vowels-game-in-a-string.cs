// public class Solution {

//     private bool isVowel(char c){
//         c = char.ToLower(c);
//         return (c == 'a' || c == 'e'||c == 'i' || c == 'o'|| c =='u');
//     }
//     private string candelete(string r, string s){
//         //string toremove = r.ToString();
//         if(s.Contains(r)){
//             s.Replace(r,"");
//         }
//         return s;
//     }
//     public bool DoesAliceWin(string s) {
//         string r = "";
//         bool isalice = true;
//         bool isbob = false; 
//         int cnt = 0;
//         foreach(char c in s){
            
//             if(isVowel(c)){
//                 cnt++;
//             }
//             r +=c;
//             if(cnt %2 != 0 && isalice == true){
//                 s = candelete(r,s);
//                 r = "";
//                 cnt == 0;
//                 isalice = false;
//                 isbob = true;
//             }
//             if((cnt %2 == 0 || cnt == 0) && isbob == true){
//                 s = candelete(r,s);
//                 r = "";
//                 cnt ==0;
//                 isbob = false;
//                 isalice = true;
//             }
//         }
//         if(isalice == true && isbob == false){
//             return false;
//         }
//         // if(isbob == true && isalice == false){
//         //     return true;
//         // }
//         else{
//             true;
//         }
//     }
// }

/////////////////////////smart solution 

public class Solution {

    private bool isVowel(char c){
        c = char.ToLower(c);
        return (c == 'a' || c == 'e'||c == 'i' || c == 'o'|| c =='u');
    }

    public bool DoesAliceWin(string s) {
        foreach(char c in s){
            if(isVowel(c)){
                return true; /// if there is even 1 vowel than alice forcefully wins
            }
        }
        return false;
    }
}