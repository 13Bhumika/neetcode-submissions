class Solution {
private:
    vector<pair<int, int>>dir = { {1,0}, {0,1}, {-1,0}, {0,-1}};

    bool dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, string &word,
    int index){
        if(index== word.size()) return true;

        int m= board.size();
        int n=board[0].size();

        for(pair<int, int> del: dir){
            int x= i+ del.first;
            int y= j+ del.second;

            if(x>=0 && x<m && y>=0 && y<n && !visited[x][y] && board[x][y] == word[index]){
                visited[x][y]= true;
                 if(dfs(board, x, y, visited, word, index +1)) return true;
                 visited[x][y]=false;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m= board.size();
        int n=board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]!= word.front()) continue;

                vector<vector<bool>> visited(m, vector<bool>(n, false));
                visited[i][j]=true;

                if(dfs(board, i, j, visited, word,1)) return true;
            }
        }
        return false;
    }
};