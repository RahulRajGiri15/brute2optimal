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


/////////// using unorderd set ///////

// class Solution {
// public:
//     bool reorderedPowerOf2(int n) {
//        unordered_set<string>st;
//        for(int p=0;p<=30;p++){
//         string poww = to_string(1 << p);
//         sort(begin(poww),end(poww));
//         st.insert(poww);
//        }
//        string s = to_string(n);
//        sort(begin(s),end(s));
//        if(!st.count(s)){
//         return false;
//        }
//        return true;
//     }
// };

/////////another way to write the code

// class Solution {
// public:
//     unordered_set<string>st;
//     void buildset(){
//         for(int p=0;p<=30;p++){
//         string poww = to_string(1 << p);
//         sort(begin(poww),end(poww));
//         st.insert(poww);
//        }
//     }
//     bool reorderedPowerOf2(int n) {
//        if(st.empty()){
//         buildset(); //// if st is empty
//        }
//        string s = to_string(n);
//        sort(begin(s),end(s));
//     //    if(!st.count(s)){
//     //     return false;
//     //    }
//     //    return true;

//         return st.count(s);
//     }
// };

//////////////// using digit count of n

// class Solution {
// public:
//     vector<int> getvectorcount(int n){
//         vector<int>vecc(10,0);
//         while(n){
//             vecc[n%10]++;
//             n = n/10;
//         }
//         return vecc;
//     }
//     bool reorderedPowerOf2(int n) {
//         vector<int> ans = getvectorcount(n);
//         for(int i=0;i<=30;i++){
//             if(ans == getvectorcount(1 << i)){
//                 return true;
//             }
//         }
//         return false;
//     }
// };


///////////another approach 
//////no need to use vector 
class Solution {
public:
    int getdigitcount(int n){
        int num = 0;
        while(n){
            int poww = pow(10,n%10);
            num += poww;
            n = n/10;
        }
        return num;
    }
    bool reorderedPowerOf2(int n) {
        int ans = getdigitcount(n);
        for(int i=0;i<=30;i++){
            if(ans == getdigitcount(1 << i)){
                return true;
            }
        }
        return false;
    }
};
