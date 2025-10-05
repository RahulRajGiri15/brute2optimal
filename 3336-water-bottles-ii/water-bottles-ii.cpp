class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank = numBottles;
        int empty = numBottles;

        while(empty >= numExchange){

            // empty = (empty - numExchange) + 1;
            // drank = drank +1;
            // numExchange++;

            /////////////////////////////////////

            empty = empty - numExchange;
            drank = drank +1;
            empty = empty +1;
            numExchange++;
            
        }
        return drank;
    }
};