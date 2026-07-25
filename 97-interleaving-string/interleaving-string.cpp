class Solution {
public:
    vector<vector<int>> dp;

    bool f(int i, int j, string &s1, string &s2, string &s3) {

        if (i + j == s3.size())
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool d1 = false, d2 = false;

        if (i < s1.size() && s1[i] == s3[i + j])
            d1 = f(i + 1, j, s1, s2, s3);

        if (j < s2.size() && s2[j] == s3[i + j])
            d2 = f(i, j + 1, s1, s2, s3);

        return dp[i][j] = d1 || d2;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() + s2.size() != s3.size())
            return false;

        dp.assign(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        return f(0, 0, s1, s2, s3);
    }
};