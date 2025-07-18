// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>pos;
//         vector<int>neg;
//         for(int num : nums){
//             if(num >=0) pos.push_back(num);
//             else if(num <0) neg.push_back(num);
//         }
//         nums.clear();
//         for(int i=0;i<pos.size();i++){
//             nums.push_back(pos[i]);
//             nums.push_back(neg[i]);
//         }
//         return nums;
//     }
// };

/////////////sloving using two pointers 

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        
        int po=0,ne=1;
        for(int num : nums){
            if(num > 0){
                ans[po] = num;
                po += 2;
            }
            else{
                ans[ne] = num;
                ne += 2;
            }
       }
        return ans;
    }
};
        
