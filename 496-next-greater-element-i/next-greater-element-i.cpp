//////////brute approach

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         unordered_map<int,int>mp2;
//         for(int i=0;i<nums2.size();i++){
//             mp2[nums2[i]] =  i;
//         }
//         vector<int>ans(n,-1);
//         for(int i=0;i<n;i++){
//             int maxi = nums1[i];
//             int idx = mp2[nums1[i]];
//             for(int j = idx+1; j < nums2.size(); j++){
//                 if(nums2[j] > maxi){
//                     maxi = nums2[j];
//                     ans[i] = nums2[j];
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };

////////////////////-- useing stack

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int>mp;

        stack<int>st;
        vector<int>res(n);
        ///1st make res arry
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            // if(st.empty()){
            //     res[i] = -1;
            // }
            // else{
            //     res[i] = st.top();
            // }

            mp[nums2[i]] = st.empty()?-1: st.top();

            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            res[i] = mp[nums1[i]];
        }
        return res;
    }
};

