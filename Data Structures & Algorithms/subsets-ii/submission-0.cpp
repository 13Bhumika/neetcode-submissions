class Solution {
private:
    void solution(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& result){
        if(i==nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solution(nums, i+1, temp, result);
        temp.pop_back();
        int j;

        for(j=i+1; j<nums.size(); j++){
            if(nums[j] == nums[j-1]) continue;
            else break;
        }
        solution(nums, j, temp, result);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end());

        solution(nums, 0, temp, result);
        return result;
    }
};