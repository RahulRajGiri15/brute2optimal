


//Approach-2 (Optimized)
//T.C : O(col * row)
//S.C : O(1) - Not considering the space of result
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> result(n, vector<char>(m));

        //Transpose
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }

        //90 degree k lie - Reverse kardo ahr row ko
        for(vector<char>& row : result) {
            reverse(begin(row), end(row));
        }


        //Apply the gravity
        //O(col * row)
        for(int j = 0; j < m; j++) {
            int spaceBottomRow = n-1;
            for(int i = n-1; i >= 0; i--) {
                if(result[i][j] == '*') {
                    spaceBottomRow = i-1;
                    continue;
                }

                if(result[i][j] == '#') {
                    result[i][j] = '.';
                    result[spaceBottomRow][j] = '#';
                    spaceBottomRow--;
                }
            }
        }

        return result;
    }
};