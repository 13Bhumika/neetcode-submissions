class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, int>> rows(9);
        vector<unordered_map<int, int>> cols(9);
        vector<unordered_map<int, int>> box(9);

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]=='.') continue;

                int num=(board[i][j]-'0');
                int boxIndex=(i/3)*3+(j/3);

                rows[i][num]++;
                cols[j][num]++;
                box[boxIndex][num]++;

                if(rows[i][num]>1 || cols[j][num]>1 || box[boxIndex][num]>1) return false; 
            }
        }
        return true;
    }
};