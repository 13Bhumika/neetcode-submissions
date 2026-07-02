class Solution {
private:
    void solution(vector<int>&candidates, int i, int target, vector<int>& temp, vector<vector<int>>&result){
        if(target<0) return;
        if(i==candidates.size()){
            if(target==0){
                result.push_back(temp);
            }
            return;
        } 
        temp.push_back(candidates[i]);

        solution(candidates, i+1, target-candidates[i], temp, result);

        temp.pop_back();
        int j;

        for(j=i+1; j<candidates.size(); j++){
            if(candidates[j]==candidates[j-1]) continue;
            else break;
        }
        solution(candidates, j, target, temp, result);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());
        solution(candidates, 0, target, temp, result);
        return result;
    }
};