class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];   // candidate for upper-left

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int x2 = points[j][0];
                int y2 = points[j][1];   // candidate for lower-right

                // Condition: (x1, y1) must be upper-left of (x2, y2)
                if (x1 <= x2 && y1 >= y2) {
                    bool hasPointInside = false;

                    // Check if some point lies inside or on the rectangle
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;

                        int x3 = points[k][0];
                        int y3 = points[k][1];

                        if (x3 >= x1 && x3 <= x2 &&
                            y3 <= y1 && y3 >= y2) {
                            hasPointInside = true;
                            break;
                        }
                    }

                    if (!hasPointInside) {
                        result++;
                    }
                }
            }
        }

        return result;
    }
};



