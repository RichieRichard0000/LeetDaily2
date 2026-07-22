class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int solve(int i, int prev, vector<int>& nums) {
        int n = nums.size();

        if (i == n)
            return 1;

        if (dp[i][prev] != -1)
            return dp[i][prev];

        long long ans = 0;

        for (int cur = prev; cur <= nums[i]; cur++) {

            if (i > 0) {
                int prevArr2 = nums[i - 1] - prev;
                int curArr2 = nums[i] - cur;

                if (curArr2 > prevArr2)
                    continue;
            }

            ans = (ans + solve(i + 1, cur, nums)) % MOD;
        }

        return dp[i][prev] = ans;
    }

    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(51, -1));

        long long ans = 0;
        for (int first = 0; first <= nums[0]; first++) {
            ans = (ans + solve(1, first, nums)) % MOD;
        }

        return ans;
    }
};