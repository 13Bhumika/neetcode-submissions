class Solution {
private:
    bool found(vector<int>& temp, int num){
        for(int x: temp){
            if(x==num) return true;
        }
        return false;
    }

    void solution(vector<int>& nums, vector<int>& temp, vector<vector<int>>& result){
        if(temp.size()==nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!found(temp,nums[i])){
                temp.push_back(nums[i]);
                solution(nums, temp, result);
                temp.pop_back();
            }
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;

        solution(nums, temp, result);
        return result;
    }
};