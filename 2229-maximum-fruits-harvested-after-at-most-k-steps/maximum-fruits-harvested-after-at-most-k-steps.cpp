class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int>prefixsum(n); // prefix sum
        vector<int>position(n); // sorted already

        for(int i=0;i<n;i++){
            position[i] = fruits[i][0];
            prefixsum[i] = fruits[i][1]+(i > 0 ? prefixsum[i-1] : 0);
        }
        int maxfruits = 0;
        
        for(int d=0; d<=k/2; d++){
            /// case moved to left
            int remain = k-2*d;
            int i = startPos-d;
            int j = startPos + remain;
            int left = lower_bound(begin(position),end(position), i) - begin(position);
            int right = upper_bound(begin(position),end(position),j) - begin(position) - 1;
            if(left <= right){
                int total = prefixsum[right] - (left > 0 ? prefixsum[left-1] : 0);
                maxfruits = max(maxfruits,total);
            }
            

            //////case 2 moved to right
            remain = k-2*d;
            i = startPos - remain;
            j = startPos + d;
            left = lower_bound(begin(position),end(position), i) - begin(position);
            right = upper_bound(begin(position),end(position),j) - begin(position) - 1;
            if(left <= right){
                int total = prefixsum[right] - (left > 0 ? prefixsum[left-1] : 0);
                maxfruits = max(maxfruits,total);
            }
        }
        return maxfruits;
    }
};

////t--o(n+klogn)
////s--o(n)