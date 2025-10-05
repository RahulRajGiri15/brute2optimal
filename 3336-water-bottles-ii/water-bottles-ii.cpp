class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank = numBottles;
        int empty = numBottles;

        while(empty >= numExchange){
            // int newbottles = empty / numExchange;
            // drank +=  newbottles;
            
            empty = (empty - numExchange) + 1;
            numExchange++;
            drank = drank +1;
        }
        return drank;
    }
};