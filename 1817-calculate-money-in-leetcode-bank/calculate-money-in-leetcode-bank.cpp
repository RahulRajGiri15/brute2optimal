class Solution {
public:
    int totalMoney(int n) {
        int i = 0;
        int sum = 0;
        int count = 0;
        int week = 0;
        if(n <= 7){
            for(int i = 1;i<=n;i++){
                sum += i;
            }
        }

        else if(n > 7){
            while(count < n){
                for(int k=1; k<=7 && count < n; k++){
                    /////every week is 1 + previous value
                    sum += (k + week);
                    count++;
                }
                week++;
            }
        }
        return sum;
    }
};