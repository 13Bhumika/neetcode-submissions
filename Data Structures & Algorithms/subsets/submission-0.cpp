class Solution {
private:
    void solution(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& result){
        if(i==nums.size()){
            result.push_back(temp);
            return;
        }
        //include
        solution(nums, i+1, temp, result);
        temp.push_back(nums[i]);
        //exclude
        solution(nums, i+1, temp, result);

        temp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;

        solution(nums, 0, temp, result);
        return result;
    }
};