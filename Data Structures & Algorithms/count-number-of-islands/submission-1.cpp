class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;

        visited[row][col] = true;
        q.push({row, col});

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (pair<int,int> &dir :directions) {
                int i = r + dir.first;
                int j = c + dir.second;

                if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() &&
                    grid[i][j] == '1' && !visited[i][j]) {
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
    }
    
    void dfs(int rows, int cols, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visited[rows][cols]=true;

        for(pair<int,int> &dir: directions){
            int i= rows+dir.first;
            int j= cols+dir.second;

            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() &&
                    grid[i][j] == '1' && !visited[i][j]) {
                    visited[i][j] = true;
                    dfs(i,j,grid,visited);
                }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islandCount = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++){
                if (grid[i][j] == '1' && !visited[i][j]) {
                    visited[i][j]=true;
                    dfs(i, j, grid, visited);
                    islandCount++;
                }
            }
        }

        return islandCount;
    }
};
            

