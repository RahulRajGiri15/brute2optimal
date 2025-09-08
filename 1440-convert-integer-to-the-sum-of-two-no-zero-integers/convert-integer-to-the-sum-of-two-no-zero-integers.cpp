// public class Solution {
//     bool isNozero(int num){
//         while(num > 0){
//             if(num %10 == 0) return false;
//             num = num/10;
//         }
//         return true;
//     }
//     public int[] GetNoZeroIntegers(int n) {
//         List<int>ans = new List<int>();
//         for(int i=1;i<n;i++){
//             int j = n-i;
//             if(isNozero(i) && isNozero(j)){
//                 //return new <int>{a,b};
//                 ans.Add(i);
//                 ans.Add(j);
//                 break;
//             }
//         }
//         Console.WriteLine(String.Join(',',ans));
//         return ans.ToArray();
//     }
// }

/////////////second method

// public class Solution{
//     bool isnozero(int num){
//         while(num > 0){
//             if(num %10 == 0) return false;
//             num = num /10;
//         }
//         return true;
//     }
//     public int[] GetNoZeroIntegers(int n){
//         List<int> arr = new List<int>();
//         for(int i=1;i<n;i++){
//             int j = n-i;
//             if(isnozero(i) && isnozero(j)){
//                 return new int[] {i , j};
//             }
//         }
//         return new int[0];
//     }
// }

/////////////in c++



class Solution {
public:
    bool isnzero(int num){
        while(num >0){
            if(num %10 == 0 ) return false;
            num /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i =1;i<n;i++){
            int j = n-i;
            if(isnzero(i) && isnzero(j)){
                return {i,j};
            }
        }
        return {};
    }
};