class Solution {
public:
    unordered_map<string, bool> t;

    bool solve(string curr, unordered_map<string, vector<char>>& mp, int idx, string above) {
        if(curr.length() == 1) { //pyramid is formed and we are at the top
            return true;
        }

        string key = curr + "_" + to_string(idx) + "_" + above;

        if(t.count(key))
            return t[key];

        if(idx == curr.length()-1) { //time to move to next row i.e. abocve row
            return t[key] =  solve(above, mp, 0, "");
        }

        string pair = curr.substr(idx, 2);
        if(mp.find(pair) == mp.end()) {
            return t[key] = false;
        }

        for(char &ch : mp[pair]) {
            above.push_back(ch); //DO

            if(solve(curr, mp, idx+1, above) == true) //EXPLORE
                return t[key] = true;
            
            above.pop_back(); //UNDO
        }

        return t[key] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;

        for(auto& pattern : allowed) {
            mp[pattern.substr(0, 2)].push_back(pattern[2]); //"ABC"
        }

        return solve(bottom, mp, 0, "");
    }
};