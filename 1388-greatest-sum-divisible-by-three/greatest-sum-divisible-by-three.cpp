class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<int>rem1;///gives remider 1 when divided by 3
        vector<int>rem2;///gives remider 2 when divided by 3
        for(int &num : nums){
            sum += num;
            if(num % 3 == 1){
                rem1.push_back(num);
            }
            else if(num % 3 == 2){
                rem2.push_back(num);
            }
        }
        
        int resrem = sum % 3;

        if(resrem == 0){
            return sum;
        }
        sort(begin(rem1),end(rem1));
        sort(begin(rem2),end(rem2));

        if(resrem == 1){
            int remove1 = (rem1.size() >= 1) ? rem1[0]: INT_MAX;
            int remove2 = (rem2.size() >= 2) ? rem2[0]+rem2[1] : INT_MAX;
            return  (sum - min(remove1 , remove2));
        }
        else if(resrem == 2){
            int remove1 = (rem2.size() >= 1) ? rem2[0] : INT_MAX;
            int remove2 = (rem1.size() >= 2)? rem1[0]+rem1[1] : INT_MAX;
            return (sum - min(remove1 , remove2));
        }

        return 0;
    }
};