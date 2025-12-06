// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int mini = prices[0];
//         int maxprofit = 0;
//         for(int i =0;i<prices.size();i++){
//             if(mini > prices[i]){
//                 mini = prices[i];
//             }
//             else{
//                 maxprofit = max(maxprofit , prices[i] - mini);
//             }
//         }
//         return maxprofit;
//     }
// };

///////////////////////

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxi = prices[0];
        int maxprofit = 0;
        int j = 0;
        for(int i =0;i<prices.size();i++){
            if(mini > prices[i]){
                mini = prices[i];
                maxi = mini; ///reset 
                j = i;
            }
            else if(prices[i] >maxi && i > j) {
                maxi = prices[i];
            }
            maxprofit = max(maxprofit , maxi - mini);
        }
        return maxprofit;
    }
};
