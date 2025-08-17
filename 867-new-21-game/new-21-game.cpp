class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> P(n + 1, 0.0);
        //P[i] = probability of getting score = i
        
        P[0] = 1; //Since already initally she has score = 0, hence probability for scoring 0 is 1
        
        double currProbabSum = k > 0 ? 1 : 0;
        
        for (int i = 1; i <= n; i++) {
            
            P[i] = currProbabSum/maxPts;
            
            if(i < k) {
                currProbabSum += P[i];
            }
            
            if(i - maxPts >= 0 && i-maxPts < k) {
                currProbabSum -= P[i-maxPts];
            }
            
        }
        return accumulate(P.begin() + k, P.end(), 0.0);
    }
};