class Solution {
private:
    int ncr(int n, int r){
        if(n==r) return 1;
        if(n<r) return 0;
        if(r==0) return 1;

        return (ncr(n-1,r-1)+ncr(n-1,r));
    }
    int solveMem(int n, int r, vector<vector<int>>& dp){
        if(n==r) return 1;
        if(n<r) return 0;
        if(r==0) return 1;
        if(dp[n][r]!=-1) return dp[n][r];

        return dp[n][r]=(solveMem(n-1,r-1,dp)+solveMem(n-1,r,dp));
    }
public:
    int uniquePaths(int m, int n) {
        int down=m-1;
        int right=n-1;
        int total= down+right;
        vector<vector<int>> dp(total+1,vector<int>(right+1,-1));
        
        return solveMem(total,right,dp);
    }
};