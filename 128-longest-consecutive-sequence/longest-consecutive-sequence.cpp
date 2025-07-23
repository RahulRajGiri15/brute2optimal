////////////brute approach 

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.empty()) return 0;
//        unordered_set<int>st;
//        int minn=nums[0],maxx=nums[0];
//        for(int num : nums){
//         st.insert(num);
//         minn = min(minn,num);
//         maxx = max(maxx,num);  
//        } 
//        int cnt=0;
//        int maxcnt=0;
//        //sort(nums.begin(),nums.end());
//        for(int i=minn;i<=maxx;i++){  ///// it will go from minn to maxx so maxtime ex:[1,100000] than it will go form 1 to 1000000 which takes a lot of time
//             if(st.find(i) != st.end()){
//                 cnt++;
//                 maxcnt = max(maxcnt , cnt);
//             }
//             else{
//                 cnt =0;
//             }
//        }
//        return maxcnt;
//     }
// };

/////////////


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int lastsmaller = INT_MIN;
        int cnt =1;
        sort(nums.begin(),nums.end());
        int maxcnt =0;
        for(int i=0;i<n;i++){
            if(nums[i]-1 == lastsmaller){
                cnt++;
                lastsmaller = nums[i];
            }
            else if(nums[i] != lastsmaller){
                cnt =1;
                lastsmaller = nums[i];
            }
            maxcnt = max(maxcnt,cnt);
        }
       return maxcnt;
    }
};