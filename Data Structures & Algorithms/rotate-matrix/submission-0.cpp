class Solution {
private:
    void transposeMatrix(vector<vector<int>>& matrix){
        for(int i=0; i<matrix.size(); i++){
            for(int j=i+1; j<matrix.size(); j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void reverseMatrix(vector<vector<int>>& matrix){
        for(vector<int>&row: matrix){
            reverse(row.begin(),row.end());
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        transposeMatrix(matrix);
        reverseMatrix(matrix);
    }
};
