class Solution {
public:
    int dfs(vector<int>&a,vector<int>&dp,int i,int d){
        if(dp[i]!=0)return dp[i];
        int mx=1,n=a.size();
        for(int j=1;j<=d && i+j<n;j++){
            if(a[i]>a[i+j]){
                mx=max(mx,1+dfs(a,dp,i+j,d));
            }else break;
        }
        for(int j=1;j<=d && i-j>=0;j++){
            if(a[i]>a[i-j]){
                mx=max(mx,1+dfs(a,dp,i-j,d));
            }else break;
        }
        return dp[i]=mx;
    }
    int maxJumps(vector<int>&arr,int d) {
        int n=arr.size();
        vector<int>dp(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dfs(arr,dp,i,d));
        }
        return ans;
    }
};