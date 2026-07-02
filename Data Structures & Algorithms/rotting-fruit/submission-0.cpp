class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh_orange = 0;
        queue<pair<int, pair<int, int>>> q;
        vector<pair<int , int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        // Count fresh oranges and enqueue all rotten oranges
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) fresh_orange++;
                else if(grid[i][j] == 2) q.push({0, {i, j}});
            }
        }

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            int curr_time = front.first;
            int i = front.second.first;
            int j = front.second.second;
            time = curr_time;

            for(pair<int, int> del : dir) {
                int row = i + del.first;
                int col = j + del.second;

                if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size()) {
                    if(grid[row][col] == 1) {
                        q.push({time + 1, {row, col}});
                        fresh_orange--;
                        grid[row][col] = 2;
                    }
                }
            }
        }

        if(fresh_orange != 0) return -1;
        else return time;
    }
};
