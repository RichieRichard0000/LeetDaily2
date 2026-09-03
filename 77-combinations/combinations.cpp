class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void f(int i, int n, int k) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        if (i > n) return;
        curr.push_back(i);
        f(i + 1, n, k);
        curr.pop_back();
        f(i + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        curr.clear();
        f(1, n, k);

        return ans;
    }
};