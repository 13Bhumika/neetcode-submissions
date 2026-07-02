class Solution {
private:
    int bfs(int rows, int cols, vector<vector<int>>& grid, vector<vector<bool>>& visited){

        int area=0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        q.push({rows,cols});

        while(!q.empty()){
            int r= q.front().first;
            int c= q.front().second;
            q.pop();
            area++;

            for(pair<int,int>& dir : directions){
                int i= r+ dir.first;
                int j = c+ dir.second;

                if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1 && !visited[i][j]){
                    visited[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        return area;
    }

    void dfs(int rows, int cols, vector<vector<int>>& grid, vector<vector<bool>> & visited,int &area){
    
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        area++;

        for(pair<int,int> &dir: directions){
            int i= rows+ dir.first;
            int j=cols+ dir.second;

            if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1 && !visited[i][j]){
                visited[i][j]=true;
                dfs(i, j, grid, visited,area);
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        int maxArea=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    visited[i][j]=true;
                    int area=0;
                    dfs(i,j,grid,visited,area);
                    maxArea= max(maxArea,area );
                }

            }
        }
        return maxArea;
    }
};