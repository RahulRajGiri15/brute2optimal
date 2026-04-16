class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> result;

        for(int qi : queries) { //O(Q)
            int element = nums[qi];
            vector<int>& vec = mp[element];

            int sz = vec.size();

            //no more occurence of this element
            if(sz == 1) {
                result.push_back(-1);
                continue;
            }

            int pos = lower_bound(begin(vec), end(vec), qi) - begin(vec); //log(n)
            int res = INT_MAX;

            //Right Neighbour - pos+1
            int right = vec[(pos+1) % sz];
            int d = abs(qi - right);//straught forqward distance
            int circularDist = n-d;
            res = min({res, d, circularDist});


            //Left Neighbour - pos-1
            int left = vec[(pos-1+sz) % sz];
            d = abs(qi - left);//straught forqward distance
            circularDist = n-d;
            res = min({res, d, circularDist});

            result.push_back(res);
        }

        return result;
    }
};
