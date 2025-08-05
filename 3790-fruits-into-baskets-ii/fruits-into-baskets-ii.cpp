class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int cnt = 0;
        int i =0,j=0;
        while(i < n){
            j =0;
            while(j < n){
                if(baskets[j] >= fruits[i]){
                    cnt++;
                    baskets[j] =0;
                    break;
                }
                j++;
            }
            i++;
        }
        return n-cnt;
    }
};

/////////////