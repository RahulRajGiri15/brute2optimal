// class Solution {
// public:
//     int totalcount(vector<int>& arr){
        
//         ////
//         int pick = totalcount(arr,idx+1,numor |num[idx],n);
//         int notpick = totalcount(arr,idx,numor,n);
//     }
//     int subarrayBitwiseORs(vector<int>& arr) {
//         int n = arr.size();
//         int result = totalcount(arr,0,n);
//     }
// };

//////////Most Brute Approach ---TLE

// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& arr) {
//         int n = arr.size();
//         unordered_set<int>st;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 int curor = 0;
//                 for(int k=i;k<=j;k++){
//                     curor |= arr[k];
//                 }
//                 st.insert(curor);
//             }
//         }
//         int cnt=0;
//         for(auto & it : st){
//             cnt++;
//         }
//         return cnt;
//     }
// };

////t-o(n^3)
////s-o(n)

////////Brute Approach ---TLE -- using two loop

// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& arr) {
//         int n = arr.size();
//         unordered_set<int>st;
//         int i = 0 , j;
//         while(i < n){
//             j = i;
//             int curor=0;
//             while(j<n){
//                 curor |= arr[j];
//                 st.insert(curor);
//                 j++;
//             }
//             i++;
//         }
//         //int cnt=0;
//         // for(auto & it : st){
//         //     cnt++;
//         // }
//         // return cnt;
//         return st.size();
//     }
// };

////t-o(n^2)
////s-o(n)

////////////Most optimal solution 

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int>prev;
        unordered_set<int>curr;
        unordered_set<int>result;
        for(int i=0;i<n;i++){
            for(auto &x : prev){
                curr.insert( x|arr[i] );
                result.insert(x|arr[i]);
            }
            curr.insert(arr[i]);
            result.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return result.size();
    }
};