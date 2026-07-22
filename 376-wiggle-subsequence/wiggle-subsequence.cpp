class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));

        int ans = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {

                if(nums[i] == nums[j]) continue;

                int diff = (nums[i] > nums[j]) ? 1 : 0;

                dp[i][!diff] = max(dp[i][!diff], dp[j][diff] + 1);

                ans = max(ans, dp[i][!diff]);
            }
        }

        return ans;
    }
};