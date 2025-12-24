class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple = accumulate(begin(apple), end(apple), 0);

        // Counting sort frequency array
        vector<int> freq(51, 0);
        for (int cap : capacity) {
            freq[cap]++;
        }

        int count = 0;

        // Start using boxes with largest capacity
        for (int cap = 50; cap >= 1 && totalApple > 0; cap--) {
            while (freq[cap] > 0 && totalApple > 0) {
                totalApple -= cap;
                freq[cap]--;
                count++;
            }
        }

        return count;
    }
};
