class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,pair<int,int>>ytominmaxx;
        unordered_map<int,pair<int,int>>xtominmaxy;
        for(auto &building : buildings){
            int x = building[0];
            int y = building[1];
            if(!ytominmaxx.count(y))
                ytominmaxx[y] = {INT_MAX,INT_MIN};
            if(!xtominmaxy.count(x))
                xtominmaxy[x] = {INT_MAX,INT_MIN};
            ytominmaxx[y].first = min(ytominmaxx[y].first,x);
            ytominmaxx[y].second = max(ytominmaxx[y].second,x);

            xtominmaxy[x].first = min(xtominmaxy[x].first,y);
            xtominmaxy[x].second = max(xtominmaxy[x].second,y);
            
        }

        int result = 0;
        for(auto &building : buildings){
            int x = building[0];
            int y = building[1];

            auto &xr = ytominmaxx[y];
            auto &yr = xtominmaxy[x];

            if(xr.first < x && x < xr.second && yr.first < y 
                && y < yr.second){
                    result++;
                }
        }
        return result;
    }
};