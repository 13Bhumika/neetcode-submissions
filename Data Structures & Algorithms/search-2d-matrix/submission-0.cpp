class Solution {
private:
    bool binarySearch(vector<int>& row, int target){
        int low=0;
        int high= row.size()-1;

        while(low<=high){
            int mid= (low+high)/2;

            if(row[mid]==target) return true;
            else if(target<row[mid]) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int high=matrix.size()-1;

        while(low<=high){
            int mid= (low+high)/2;

            if(target>=matrix[mid].front() && target<=matrix[mid].back()) return binarySearch(matrix[mid],target);
            else if(target<matrix[mid].back()) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};