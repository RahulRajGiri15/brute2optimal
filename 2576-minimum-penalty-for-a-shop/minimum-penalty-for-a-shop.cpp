class Solution {
public:
    int bestClosingTime(string customers) {
        int n           = customers.length();
     
        vector<int> prefixN(n+1, 0);
        prefixN[0] = 0;
            
        vector<int> suffixY(n+1, 0);
        suffixY[n] = 0;
        
        for(int i = 1; i<=n; i++) {
            if(customers[i-1] == 'N') {
                prefixN[i] = prefixN[i-1] + 1;
            } else {
                prefixN[i] = prefixN[i-1];
            }
        }
        
        for(int i = n-1; i >= 0; i--) {
            if(customers[i] == 'Y') {
                suffixY[i] = suffixY[i+1]+1;
            } else {
                suffixY[i] = suffixY[i+1];   
            }
        }
        
        int minPenalty = INT_MAX;
        int minHour    = INT_MAX;
        
        for(int i = 0; i<n+1; i++) {
            int currPenalty = prefixN[i] + suffixY[i];
            
            if(currPenalty < minPenalty) {
                minPenalty = currPenalty;
                minHour    = i;
            }
        }
        
        return minHour;
    }
};
