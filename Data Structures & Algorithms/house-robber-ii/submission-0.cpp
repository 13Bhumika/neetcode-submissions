class Solution {
private:
    int solveRec(vector<int>& nums,int i,int end){
        if(i>=end) return 0;
        

        int include= solveRec(nums,i+2,end)+nums[i];
        int exclude= solveRec(nums,i+1,end);
        return max(include,exclude);
        
    }
    int solveMem(vector<int>& nums,int i,int end,vector<int>& dp){
        if(i>=end) return 0;
        if(dp[i]!=-1) return dp[i];

        int include= solveMem(nums,i+2,end,dp)+nums[i];
        int exclude= solveMem(nums,i+1,end,dp);

        return dp[i]= max(include,exclude);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        int result1=solveMem(nums,0,nums.size()-1,dp1);
        int result2= solveMem(nums,1,nums.size(),dp2);
        return max(result1,result2);
        
    }
};