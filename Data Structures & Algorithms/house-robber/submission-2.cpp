class Solution {
private:
    int solveRec(vector<int>& nums, int i){
        if(i>=nums.size()) return 0;

        int way1= solveRec(nums, i+2)+nums[i];
        int way2= solveRec(nums, i+1);

        return max(way1,way2);
    }
    int solveMem(vector<int>& nums, int i, vector<int> & dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int way1= solveMem(nums, i+2,dp)+nums[i];
        int way2= solveMem(nums, i+1,dp);

        return dp[i]=max(way1,way2);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solveMem(nums,0,dp);
    }
};
