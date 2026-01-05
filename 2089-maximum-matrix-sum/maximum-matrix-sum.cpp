class Solution {
public:
    typedef long long ll;
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int mini = INT_MAX;
        int count = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));
                if(matrix[i][j] < 0){
                    count++;
                }
            }
        }
        if(count % 2 == 0){
            return sum;
        }
        return sum - (2ll * mini);
    }
};