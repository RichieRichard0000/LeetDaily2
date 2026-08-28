class Solution {
public:
    int n;
    int dp[201][201];
    int solve(vector<int>&nums,int idx,int k){
        if(idx==n)return 0;
        if(k<0)return 1e9;
        if(dp[idx][k]!=-1)return dp[idx][k];
        int mini=1e9;
        int maxi=0;
        int sum=0;
        for(int i=idx;i<n;i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
            int curr=(i-idx+1)*maxi-sum;
            int nxt=solve(nums,i+1,k-1);//k-1 bina kisi check ke
            mini=min(mini,curr+nxt);
        }
        return dp[idx][k]=mini;
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,k);
    }
};