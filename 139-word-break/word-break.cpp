class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {

                string temp = s.substr(j, i - j + 1);

                if (st.count(temp)) {
                    if (j == 0) {
                        dp[i] = 1;
                    } else if (dp[j - 1]) {
                        dp[i] = 1;
                    }
                }

                if (dp[i]) break;
            }
        }

        return dp[n - 1];
    }
};