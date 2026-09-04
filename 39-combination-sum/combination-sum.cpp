class Solution {
public:
    vector<int> curr;
    vector<vector<int>> ans;

    void f(int i, int sum, vector<int>& candidates, int n, int target) {
        if (sum == target) {
            ans.push_back(curr);
            return;
        }

        if (i == n) return;
        if (sum + candidates[i] <= target) {
            curr.push_back(candidates[i]);
            f(i, sum + candidates[i], candidates, n, target);

            curr.pop_back();
        }
        f(i + 1, sum, candidates, n, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        ans.clear();
        curr.clear();

        f(0, 0, candidates, candidates.size(), target);

        return ans;
    }
};