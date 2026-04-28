class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> vec;
        //O(m*n)
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vec.push_back(grid[i][j]);
            }
        }

        int L = vec.size(); //m*n

        //sort(begin(vec), end(vec)); //O(LlogL)
        nth_element(begin(vec), begin(vec) + L/2, end(vec)); //O(L)
        //{4, 2, 8, 6}
        //{4, 2, 6, 8} - nth_element
        //{2, 4, 6, 8} - complete sorting

        int target = vec[L/2];
        int result = 0;
        for(int &num : vec) { //O(m*n)
            if(num%x != target%x) {
                return -1;
            }

            result += abs(target-num)/x;
        }

        return result;
    }
};

