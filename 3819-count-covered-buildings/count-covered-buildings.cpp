//Approach (storing in Map and checking)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int,int>> yToMinMaxX;
        unordered_map<int, pair<int,int>> xToMinMaxY;

        for (auto &building : buildings) {
            int x = building[0];
            int y = building[1];

            if (!yToMinMaxX.count(y))
                yToMinMaxX[y] = {INT_MAX, INT_MIN};

            if (!xToMinMaxY.count(x))
                xToMinMaxY[x] = {INT_MAX, INT_MIN};

            yToMinMaxX[y].first  = min(yToMinMaxX[y].first, x);
            yToMinMaxX[y].second = max(yToMinMaxX[y].second, x);

            xToMinMaxY[x].first = min(xToMinMaxY[x].first, y);
            xToMinMaxY[x].second = max(xToMinMaxY[x].second, y);
        }

        int result = 0;

        for (auto &building : buildings) {
            int x = building[0];
            int y = building[1];


            auto &xr = yToMinMaxX[y];
            auto &yr = xToMinMaxY[x];

            if (xr.first < x && x < xr.second &&
                yr.first < y && y < yr.second) {
                result++;
            }
        }

        return result;
    }
};
