class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        map<int,vector<int>>mp;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        bool flip = true;
        for(auto &it : mp){
            if(flip){
                /////every odd elemnent has to reverserved from i+j flow;
                reverse(it.second.begin(),it.second.end());
            }
            for(auto &num : it.second){
                ans.push_back(num);
            }
            flip = !flip;
        }
        return ans;
    }
};