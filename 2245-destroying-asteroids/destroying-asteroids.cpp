class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));

        for(int &asteroid : asteroids) {
            if(mass < asteroid)
                return false;
            else if(mass >= 1e5)
                return true;

            mass += asteroid;
        }

        return true;
    }
};