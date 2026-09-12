class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void f(int idx, vector<int>& nums) {

        if (curr.size() >= 2) {
            ans.push_back(curr);
        }

        unordered_set<int> used;

        for (int i = idx; i < nums.size(); i++) {
            if (used.count(nums[i]))
                continue;
            if (!curr.empty() && nums[i] < curr.back())
                continue;

            used.insert(nums[i]);

            curr.push_back(nums[i]);

            f(i + 1, nums);

            curr.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        ans.clear();
        curr.clear();

        f(0, nums);

        return ans;
    }
};