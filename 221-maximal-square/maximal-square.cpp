class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int mx = 0;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (matrix[i][j] == '0')
                    continue;

                if (i == m - 1 || j == n - 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 1 + min({
                        dp[i+1][j],
                        dp[i][j+1],
                        dp[i+1][j+1]
                    });

                mx = max(mx, dp[i][j]);
            }
        }

        return mx * mx;
    }
};