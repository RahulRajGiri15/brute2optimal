class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank =  numBottles;
        int empty = numBottles;
        
        while(empty >= numExchange){
            int newbottle = empty / numExchange;  ///new bootles to drink
            drank += newbottle;                 ////add them in total
            empty = (empty % numExchange) + newbottle; //// leftover + new empty bottles

        }

        return drank;
    }
};