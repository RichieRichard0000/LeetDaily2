class Solution {
public:
    vector<int> ans;

    int dfs(int u, vector<vector<int>>& adj,
            vector<int>& quiet) {

        if (ans[u] != -1)
            return ans[u];

        ans[u] = u;

        for (int v : adj[u]) {

            int candidate = dfs(v, adj, quiet);

            if (quiet[candidate] < quiet[ans[u]])
                ans[u] = candidate;
        }

        return ans[u];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer,
                            vector<int>& quiet) {

        int n = quiet.size();

        vector<vector<int>> adj(n);

        // Reverse the relationships:
        // poorer -> richer
        for (auto e : richer) {
            int rich = e[0];
            int poor = e[1];

            adj[poor].push_back(rich);
        }

        ans.assign(n, -1);

        for (int i = 0; i < n; i++) {
            dfs(i, adj, quiet);
        }

        return ans;
    }
};