class Solution {
public:
    //SImplified
    int MAH(vector<int>& heights, int& n) {
        stack<int> st;
        int i = 0;
        int maxArea = 0;
        int area = 0;
        while(i < n) {
            if(st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i++);
            } else {
                int index = st.top();
                st.pop();
                
                if(st.empty()) {
                    area = heights[index] * i;
                } else {
                    area = heights[index] * (i - st.top() - 1);
                }
                
                maxArea = max(maxArea, area);
            }
        }
        
        while(!st.empty()) {
            int index = st.top();
            st.pop();

            if(st.empty()) {
                area = heights[index] * i;
            } else {
                area = heights[index] * (i - st.top() - 1);
            }

            maxArea = max(maxArea, area);
        }
        
        return maxArea;
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        
        int maxArea = 0;
        int m       = matrix.size();
        int n       = matrix[0].size();
        
        /*
        [1, 0, 1, 0, 0]
        [1, 0, 1, 1, 1] =>  [2, 0, 2, 1, 1]
        [1, 1, 1, 1, 1] =>  [3, 1, 3, 2, 2]
        [1, 0, 0, 1, 0] ->  [3, 0, 0, 3, 0]
        */
        
        vector<int> heights(n, 0);
        for(int col = 0; col < n; col++) {
            heights[col] = matrix[0][col] == '0' ? 0 : 1;
        }
        
        maxArea = MAH(heights, n);
        
        for(int row = 1; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(matrix[row][col] == '0') {
                    heights[col] = 0;
                } else {
                    heights[col] += 1;
                }
            }
            
            maxArea = max(maxArea, MAH(heights, n));
        }
        
        return maxArea;
    }
};

