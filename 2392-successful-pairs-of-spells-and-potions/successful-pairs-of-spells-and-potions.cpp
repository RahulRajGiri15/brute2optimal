/////////////tle

// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         vector<int>ans;
//         for(int i=0;i<spells.size();i++){
//             int count = 0;
//             for(int j=0;j<potions.size();j++){
//                 if(((long long)spells[i]*potions[j]) >= success){
//                     count++;
//                 }
//             }
//             ans.push_back(count);
//         }
//         return ans;
//     }
// };

/////t-o(m*n)
////s-o(n);

////////////////////////////////

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        int n = potions.size();

        sort(potions.begin(),potions.end());
        int maxpotions = potions[n-1];
        vector<int>ans;
        for(int i=0;i<m;i++){
            int spell = spells[i];
            long long  minpotions = ceil(1.0*success/spell);

            if(minpotions > maxpotions){
                ans.push_back(0);
                continue;
            }
            int index = lower_bound(begin(potions),end(potions),minpotions) - begin(potions);
            int size = n - index;
            
            ans.push_back(size);
        }
        return ans;
    }
};

/////t-o(m*n)
////s-o(n);