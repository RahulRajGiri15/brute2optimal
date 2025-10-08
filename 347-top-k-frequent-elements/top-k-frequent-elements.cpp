// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int>mp;
//         for(int no : nums){
//             mp[no]++;
//         }
//         vector<pair<int,int>>freq;
//         for(auto &it : mp){
//             freq.push_back({it.first,it.second});
//         }
//         sort(begin(freq),end(freq),[](auto &a,auto &b){  ////o(mlogm)
//             return a.second > b.second;
//         });

//         vector<int>ans;

//         for(int i=0;i<k;i++){
//             ans.push_back(freq[i].first);
//         }
//         return ans;
//     }
// };

///////////////////////////////

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int no : nums){
            mp[no]++;
        }
        vector<pair<int,int>>freq;

        for(auto &it : mp){
            freq.push_back({it.second,it.first});
        }
        sort(begin(freq),end(freq),greater<>());

        vector<int>ans;

        for(int i=0;i<k;i++){
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};