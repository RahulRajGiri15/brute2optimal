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

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int>mp;
//         for(int no : nums){
//             mp[no]++;
//         }
//         vector<pair<int,int>>freq;

//         for(auto &it : mp){
//             freq.push_back({it.second,it.first});
//         }
//         sort(begin(freq),end(freq),greater<>()); ////ascending order

//         vector<int>ans;

//         for(int i=0;i<k;i++){
//             ans.push_back(freq[i].second);
//         }
//         return ans;
//     }
// };

////////////////////using min heap


class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int no : nums){
            mp[no]++;
        }
        //priority_queue<int,vector<int>,greater<int>> pq; ///// min heap
        priority_queue<p,vector<p>,greater<p>>pq;

        for(auto &it : mp){
            int first = it.first;
            int second = it.second;
            pq.push({second,first});

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};