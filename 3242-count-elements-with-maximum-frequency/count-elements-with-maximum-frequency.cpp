class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp; 
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int count=0;
        int maxel = -1;
        int maxcount =0;
        for(auto &it : mp){
           if(it.second > maxel){
            maxel = it.second;
            count =0;
            maxcount = 0;

           } 
           if(maxel == it.second){
            count = count + it.second;
            maxcount = max(maxcount,count);
           }
        }
        return maxcount;
    }
};

///t--O(n) ; n= size of nums
///s---o(n)