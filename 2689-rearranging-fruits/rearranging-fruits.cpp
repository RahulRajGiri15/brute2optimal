// class Solution {
// public:
//     long long minCost(vector<int>& basket1, vector<int>& basket2) {
//         unordered_map<int,int>mp;
//         int minel = INT_MAX;
//         for(int &x : basket1){
//             mp[x]++;
//             minel = min(x,minel);
//         }
//         for(int &x : basket2){
//             mp[x]--;
//             minel = min(x,minel);
//         }
//         vector<int>finallist;
//         for(auto &it : mp){
//             int cost = it.first;
//             int count = it.second;

//             if(count == 0){
//                  continue; ////equal num is present on both side
//             }
//             if(count %2 != 0){ /// we can't value
//                 return -1;
//             }
//             for(int i=1;i<= abs(count)/2;i++){
//                 finallist.push_back(cost);
//             }
//         }
//         long long  result = 0;
//         ////
//         sort(begin(finallist),end(finallist));
//         for(int i=0;i<finallist.size()/2;i++){
//             result += min(finallist[i], minel*2);
//         }

//         return result;
//     }
// };


////////////////

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp;
        int minel = INT_MAX;
        for(int &x : basket1){
            mp[x]++;
            minel = min(x,minel);
        }
        for(int &x : basket2){
            mp[x]--;
            minel = min(x,minel);
        }
        vector<int>finallist;
        for(auto &it : mp){
            int cost = it.first;
            int count = it.second;

            if(count == 0){
                 continue; ////equal num is present on both side
            }
            if(count %2 != 0){ /// we can't value
                return -1;
            }
            for(int i=1;i<= abs(count)/2;i++){
                finallist.push_back(cost);
            }
        }
        long long  result = 0;
        //////
        // sort(begin(finallist),end(finallist));
        // for(int i=0;i<finallist.size()/2;i++){
        //     result += min(finallist[i], minel*2);
        // }

        ////////////or
        ///we don't need to sort all the elment just we just need first half thats all
        nth_element(begin(finallist),begin(finallist)+finallist.size()/2,end(finallist));
        ///The element at the middle position (finallist.size()/2) is what would be there if the array was sorted

/////All elements before it are ≤ it, and all after it are ≥ it (but not fully sorted)
        for(int i=0;i<finallist.size()/2;i++){
            result += min(finallist[i], minel*2);
        }
        return result;
    }
};
