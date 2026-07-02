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
        //include
        temp.push_back(candidates[i]);
        solution(candidates, i, target-candidates[i], temp, result);

        temp.pop_back();
        //exclude
        solution(candidates, i+1, target, temp, result);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;

        solution(candidates, 0, target, temp, result);
        return result;
    }
};