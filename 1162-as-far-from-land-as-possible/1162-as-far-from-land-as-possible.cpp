class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> q;

        // Push all land cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }

        // If all water or all land
        if (q.empty() || q.size() == n * n)
            return -1;

        vector<pair<int, int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        int distance = -1;

        while (!q.empty()) {
            int sz = q.size();
            distance++;

            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto d : dir) {
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if (nx >= 0 && ny >= 0 &&
                        nx < n && ny < n &&
                        grid[nx][ny] == 0) {

                        grid[nx][ny] = 1;   // mark visited
                        q.push({nx, ny});
                    }
                }
            }
        }

        return distance;
    }
};