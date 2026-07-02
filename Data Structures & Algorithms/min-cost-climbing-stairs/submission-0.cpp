class Solution {
private:
    int solveRec(vector<int>& cost, int i){
        if(i>=cost.size()) return 0;

        return min(solveRec(cost,i+1), solveRec(cost,i+2)) + cost[i];
    }
    int solveMem(vector<int>& cost, int i, vector<int>& dp){
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        return dp[i]=min(solveMem(cost,i+1,dp), solveMem(cost,i+2,dp)) + cost[i];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return min(solveMem(cost,0,dp), solveMem(cost,1,dp));
    }
};
