class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges
    ) {
        vector<int> ans(n, -1);
        ans[0] = 0;

        vector<vector<int>> red_adj(n, vector<int>(n, 0));
        vector<vector<int>> blue_adj(n, vector<int>(n, 0));

        for (auto it : redEdges)
            red_adj[it[0]][it[1]] = 1;

        for (auto it : blueEdges)
            blue_adj[it[0]][it[1]] = 1;

        // visited[node][0] -> reached node using RED edge
        // visited[node][1] -> reached node using BLUE edge
        vector<vector<bool>> vis(n, vector<bool>(2, false));

        queue<pair<int, char>> q;

        // First edge can be either color
        for (int i = 0; i < n; i++) {
            if (red_adj[0][i]) {
                q.push({i, 'r'});
                vis[i][0] = true;
            }

            if (blue_adj[0][i]) {
                q.push({i, 'b'});
                vis[i][1] = true;
            }
        }

        int dist = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto curr = q.front();
                q.pop();

                int node = curr.first;
                char color = curr.second;

                // First time reaching node = shortest distance
                if (ans[node] == -1)
                    ans[node] = dist;

                // Last edge was RED -> next must be BLUE
                if (color == 'r') {
                    for (int i = 0; i < n; i++) {
                        if (blue_adj[node][i] && !vis[i][1]) {
                            vis[i][1] = true;
                            q.push({i, 'b'});
                        }
                    }
                }

                // Last edge was BLUE -> next must be RED
                else {
                    for (int i = 0; i < n; i++) {
                        if (red_adj[node][i] && !vis[i][0]) {
                            vis[i][0] = true;
                            q.push({i, 'r'});
                        }
                    }
                }
            }

            dist++;
        }

        return ans;
    }
};