class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
         vector<pair<int,int>> sortedNums;
        for(int i = 0 ; i < n; i++ )
        {
            sortedNums.push_back({nums[i],i});
        }
        sort(sortedNums.begin() , sortedNums.end());

        unordered_map<int,int>  point ;

        for(int i = 0 ; i< n; i++ )
        {
            point[sortedNums[i].second] = i ; // points[old] = sorted_one
        }

        vector<int> up(n+1,0); // parent
        int j =0;
        for(int i = 0 ; i< n ;i++ ){
            while(j+1 <n && (sortedNums[j+1].first - sortedNums[i].first)<= maxDiff){
                j++;
            }
            if( j<i)j =i;
            up[i] = j;
        }
        int temp = n;

        int k = 0 ; // log(n)
        while(temp!=0){
            k++;
            temp/=2;
        }

        vector<vector<int>> dp(n+1 , vector<int>(k+1,0));

        for(int i = 0 ; i< n; i++ ){
            dp[i][0] = up[i];
        }

        for(int j = 1 ; j < k ; j++ ){
            for(int i =0 ; i <n ;i++ )
            {
                dp[i][j] = dp[ dp[i][j-1] ][j-1];
            }
        }

        vector<int> res;

        for(vector<int>& q : queries )
        {
            int u = q[0] , v = q[1];

            if(u==v)
            {
                res.push_back(0);
                continue;
            }

            int st = min(point[u],point[v]) , en = max(point[u],point[v]);

            if(up[st]==st){
                res.push_back(-1);
                continue;
            }
            int node = st;
            int step = 0;
            for(int i = k-1 ; i>=0 ; i--){
                if(dp[node][i] < en ){
                    node = dp[node][i];
                    step += 1<<i;
                }
            }
            if(up[node] < en )res.push_back(-1);
            else res.push_back(step+1);

        }
        return res;
    }
};