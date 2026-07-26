class Solution {
public:
    unordered_map<string,int> dp;

    int LCS(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][m];
    }

    int f(string curr, vector<string>& words){

        if(dp.count(curr))
            return dp[curr];

        int ans=1;

        for(int i=0;i<words.size();i++){

            if(words[i].size()-curr.size()==1 &&
               LCS(words[i],curr)==curr.size()){

                ans=max(ans,1+f(words[i],words));
            }

        }

        return dp[curr]=ans;
    }

    int longestStrChain(vector<string>& words) {

        int ans=1;

        for(int i=0;i<words.size();i++)
            ans=max(ans,f(words[i],words));

        return ans;
    }
};