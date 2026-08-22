class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        int cnt = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'X' && !vis[i][j]) {

                    cnt++;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;

                    while (!q.empty()) {

                        auto [x, y] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {

                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if (nx >= 0 && nx < n &&
                                ny >= 0 && ny < m &&
                                board[nx][ny] == 'X' &&
                                !vis[nx][ny]) {

                                vis[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        return cnt;
    }
};