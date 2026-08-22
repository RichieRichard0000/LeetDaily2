class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        // Put ALL land cells into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        // All land or all water
        if (q.empty() || q.size() == n * m)
            return -1;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        int ans = -1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && nx < n &&
                        ny >= 0 && ny < m &&
                        grid[nx][ny] == 0) {

                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }

            ans++;
        }

        return ans;
    }
};