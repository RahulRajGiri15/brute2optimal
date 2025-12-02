class Solution {
public:
    int M = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        for(auto &point : points){
            //int y = point[1];
            mp[point[1]]++;
        }

        long long res = 0;
        long long prevhorizantallines = 0;

        for(auto &it : mp){
            long long count = it.second;
            long long currhorizantallines = (count * (count - 1)) /2;
            res += currhorizantallines * prevhorizantallines;
            prevhorizantallines = prevhorizantallines + currhorizantallines;
        }
        return res % M;
    }
};