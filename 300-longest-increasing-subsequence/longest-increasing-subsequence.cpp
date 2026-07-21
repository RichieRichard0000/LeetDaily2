class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        vector<int> v(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    v[i] = max(v[i], 1 + v[j]);
                    ans = max(ans, v[i]);
                }
            }
        }
        return ans;
    }
};