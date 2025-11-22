class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(int &no : nums){
            int r = no % 3;
            if(r == 1){
                count +=1; ////sub 1 to make divisible
            }
            else if(r == 2){
                count += 1; ///add 1 to the num to make div by 3
            }
        }
        return count;
    }
};