// class Solution {
// public:
//     int maxSumDivThree(vector<int>& nums) {
//         int sum = 0;
//         int n = nums.size();
//         vector<int>rem1;///gives remider 1 when divided by 3
//         vector<int>rem2;///gives remider 2 when divided by 3
//         for(int &num : nums){
//             sum += num;
//             if(num % 3 == 1){
//                 rem1.push_back(num);
//             }
//             else if(num % 3 == 2){
//                 rem2.push_back(num);
//             }
//         }
        
//         int resrem = sum % 3;

//         if(resrem == 0){
//             return sum;
//         }
//         sort(begin(rem1),end(rem1));
//         sort(begin(rem2),end(rem2));
    
//         if(resrem == 1){
//             int remove1 = (rem1.size() >= 1) ? rem1[0]: INT_MAX;
//             int remove2 = (rem2.size() >= 2) ? rem2[0]+rem2[1] : INT_MAX;
//             return  (sum - min(remove1 , remove2));
//         }
//         else if(resrem == 2){
//             int remove1 = (rem2.size() >= 1) ? rem2[0] : INT_MAX;
//             int remove2 = (rem1.size() >= 2)? rem1[0]+rem1[1] : INT_MAX;
//             return (sum - min(remove1 , remove2));
//         }

//         return 0;
//     }
// };


////////////////////////////


// class Solution {
// public:
//     int maxSumDivThree(vector<int>& nums) {
//         int sum = 0;
//         int n = nums.size();
//         vector<int>rem1;///gives remider 1 when divided by 3
//         vector<int>rem2;///gives remider 2 when divided by 3
//         for(int &num : nums){
//             sum += num;
//             if(num % 3 == 1){
//                 rem1.push_back(num);
//             }
//             else if(num % 3 == 2){
//                 rem2.push_back(num);
//             }
//         }
        
//         int resrem = sum % 3;

//         if(resrem == 0){
//             return sum;
//         }
//         sort(begin(rem1),end(rem1));
//         sort(begin(rem2),end(rem2));
//         int result = 0;
//         if(resrem == 1){
//             int remove1 = (rem1.size() >= 1) ? rem1[0]: INT_MAX;
//             int remove2 = (rem2.size() >= 2) ? rem2[0]+rem2[1] : INT_MAX;
//             result = max(result, (sum - min(remove1 , remove2)));
//         }
//         else if(resrem == 2){
//             int remove1 = (rem2.size() >= 1) ? rem2[0] : INT_MAX;
//             int remove2 = (rem1.size() >= 2)? rem1[0]+rem1[1] : INT_MAX;
//             result = (result , (sum - min(remove1 , remove2)));
//         }

//         return result;
//     }
// };


///////////////////////////



// class Solution {
// public:
//     int solve(int i , int rem, vector<int>& nums){
//         if(i >= nums.size()){
//             if(rem == 0){ ////right answer
//                 return 0;
//             }
//             else{ /////wrong answer 
//                 return INT_MIN;
//             }
//         }
//         int take = nums[i] + solve(i+1, (rem + nums[i]) %3, nums);
//         int nottake = solve(i+1, rem , nums);

//         return max(take , nottake);
//     }
//     int maxSumDivThree(vector<int>& nums) {
//         int sum = 0;
//         int n = nums.size();
//         int result = 0;
//         result = solve(0 , 0 , nums);
//         return result;
//     }
// };

///////////////////////



// class Solution {
// public:
//     int solve(int i , int rem, vector<int>& nums,vector<vector<int>>& t){
//         if(i >= nums.size()){
//             if(rem == 0){ ////right answer
//                 return 0;
//             }
//             else{ /////wrong answer 
//                 return INT_MIN;
//             }
//         }
//         if(t[i][rem] != -1){
//             return t[i][rem];
//         }
//         int take = nums[i] + solve(i+1, (rem + nums[i]) %3, nums,t);
//         int nottake = solve(i+1, rem , nums,t);

//         return t[i][rem] = max(take , nottake);
//     }
//     int maxSumDivThree(vector<int>& nums) {
//         int sum = 0;
//         int n = nums.size();
//         int result = 0;
//         vector<vector<int>> t(n , vector<int>(3,-1));
//         result = solve(0 , 0 , nums,t);
//         return result;
//     }
// };

///////////////////////


// class Solution {
// public:
//     int solve(int i , int rem, vector<int>& nums,vector<vector<int>>& t){
//         if(i >= nums.size()){
//             if(rem == 0){ ////right answer
//                 return 0;
//             }
//             else{ /////wrong answer 
//                 return INT_MIN;
//             }
//         }
//         if(t[i][rem] != -1){
//             return t[i][rem];
//         }
//         int take = nums[i] + solve(i+1, (rem + nums[i]) %3, nums,t);
//         int nottake = solve(i+1, rem , nums,t);

//         return t[i][rem] = max(take , nottake);
//     }
//     int maxSumDivThree(vector<int>& nums) {
//         int sum = 0;
//         int n = nums.size();
//         int result = 0;
//         vector<vector<int>> t(n , vector<int>(3,-1));
//         result = solve(0 , 0 , nums,t);
//         return result;
//     }
// };

//////////////////


class Solution {
public:

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> t(n+1, vector<int>(3,INT_MIN));
        t[n][0] = 0; ///// i == n and rem == 0--
        t[n][1] = INT_MIN; /// i>n--wrong answer
        t[n][2] = INT_MIN;
        for(int i = n-1; i>=0; i--){
            for(int rem = 0; rem<=2; rem++){

                int newrem = (rem + nums[i]) % 3;
                int take = (t[i+1][newrem] == INT_MIN)?INT_MIN : (nums[i] + t[i+1][newrem]);
                int skip = t[i+1][rem];
                t[i][rem] = max(take ,skip);
            }
        }
        return t[0][0];
    }
};