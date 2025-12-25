class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long result = 0;
        
        int count = 0;
        
        priority_queue<int> pq; //max-heap
        
        for(int &hap : happiness) {
            pq.push(hap);
        }
        
        for(int i = 0; i < k; i++) {
            
            int hap = pq.top();
            pq.pop();
            
            result += max(hap - count, 0);
            
            count++;
            
        }
        
        return result;
    }
};

