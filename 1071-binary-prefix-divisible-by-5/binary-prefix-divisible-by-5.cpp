class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int curr = 0 ;
        int n = nums.size();
        vector<bool>res(n,false);
        for(int i=0;i<n;i++){
            curr = ((curr * 2) +nums[i]) % 5;
            if(curr == 0){
                res[i] = true;
            }
        }
        return res;
    }
};


//////////////////////////////////
// class Solution {
// public:
//     vector<bool> prefixesDivBy5(vector<int>& nums) {
//         int curr = 0 ;
//         int n = nums.size();
//         vector<bool>res(n,false);
//         for(int i=0;i<n;i++){
//             curr = (curr * 2) +nums[i];
//             if(curr %  5 == 0){
//                 res[i] = true;
//             }
//         }
//         return res;
//     }
// };



/////////////////////////////
// class Solution {
// public:
//     vector<bool> prefixesDivBy5(vector<int>& nums) {
//         //int sum = 0 ;
//         int n = nums.size();
//         vector<bool>res(n,false);
//         for(int i=0;i<nums.size();i++){
//             int sum =0 ;
//             for(int j=i;j>=0;j--){
//                 sum += nums[j] * pow(2,j);
//             }
//             if(sum % 5 == 0){
//                     res[i] = true;
//             }
//         }
//         return res;
//     }
// };


////////////////////////////