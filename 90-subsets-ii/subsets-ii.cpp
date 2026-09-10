class Solution {
public:
    vector<int> curr;
    vector<vector<int>> ans;

    void f(int i, int n, vector<int>& nums) {
        if (i == n) {
            ans.push_back(curr);
            return;
        } 
        curr.push_back(nums[i]);
        f(i + 1, n, nums);
        curr.pop_back();
        int j = i + 1;
        while (j < n && nums[j] == nums[i]) {
            j++;
        }

        f(j, n, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        curr.clear();
        ans.clear();

        f(0, nums.size(), nums);

        return ans;
    }
};