class Solution {
private:
    int solveRec(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;

        return solveRec(n-1)+solveRec(n-2);          
}
    int solveMem(int n, vector<int>& dp){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];

        return dp[n]= solveMem(n-1,dp)+solveMem(n-2,dp);
}
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solveMem(n,dp);
    }
};