class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n , 1);
        unordered_map<int,int>mp; ////first day rain -> index
        set<int>st; //////////zero day  in sorted fasion

        for(int i=0; i<n; i++){
            int lake = rains[i];
            if(lake == 0){
                st.insert(i);
            }
            else{
                ////lake > 0
                ans[i] = -1;
                //// check if that lake is already filled
                if(mp.count(lake)){ 
                    /// if filled - than find if there is an zero rain day
                    auto it = st.lower_bound(mp[lake]);
                    if(it == st.end()){ /// no zero rain day was found
                        return {};
                    }
                    else{
                        int day = *it;
                        ans[day] = lake;
                        st.erase(it);
                    }
                }
            }
            mp[lake] = i;
        }
        return ans;
    }
};