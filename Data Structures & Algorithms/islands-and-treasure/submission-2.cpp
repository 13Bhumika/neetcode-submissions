class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;

    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 0) {
                q.push({r, c});
            }
        }
    }

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (pair<int, int>& dir : directions) {
            int i = r + dir.first;
            int j = c + dir.second;

            if (i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] == INT_MAX) {
                grid[i][j] = grid[r][c] + 1;
                q.push({i, j});
                }
            }
        }        
    }
};
