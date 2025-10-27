class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int result = 0;
        int prev = 0;
        for(int i=0;i<n;i++){
            int curr =0;
            for(char ch : bank[i]){
                if(ch == '1'){
                    curr++;
                }
            }
            if(curr != 0){
                result += prev * curr;
                prev = curr;
            }            
        }
        return result;
    }
};