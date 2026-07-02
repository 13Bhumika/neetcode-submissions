class Solution {
private:
    int solveRec1(vector<int>& coins, int i, int amount) {
        if(amount == 0) return 0;
        else if(i == coins.size())  return 1e9;
        else if(amount < 0) return 1e9;

        //include
        int include = solveRec1(coins, i, amount - coins[i]) + 1;
        //exclude
        int exclude = solveRec1(coins, i + 1, amount);

        return min(include, exclude);
    }
    int solveRec2(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        else if(amount < 0) return 1e9;

        int result = 1e9;

        for(int i = 0 ; i < coins.size() ; i ++) {
            result = min(result, solveRec2(coins, amount - coins[i]) + 1);
        }

        return result;
    }
    
    int solveMem1(vector<int>& coins, int i, int amount, vector<vector<int>>&dp){
        if(amount == 0) return 0;
        else if(i == coins.size())  return 1e9;
        else if(amount < 0) return 1e9;

        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }

        //include
        int include = solveMem1(coins, i, amount - coins[i],dp) + 1;
        //exclude
        int exclude = solveMem1(coins, i + 1, amount,dp);

        return dp[i][amount]= min(include, exclude);
    }

    int solveMem2(vector<int>& coins, int amount, vector<int>& dp) {
        if(amount == 0) return 0;
        else if(amount < 0) return 1e9;
        if(dp[amount]!=-1) return dp[amount];
        int result = 1e9;

        for(int i = 0 ; i < coins.size() ; i ++) {
            result = min(result, solveMem2(coins, amount - coins[i],dp) + 1);
        }

        return dp[amount]=result;
    }
    

public:
    int coinChange(vector<int>& coins, int amount) {
    //vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1,-1));
    vector<int>dp(amount+1,-1);
    int result =solveMem2(coins,amount,dp);
    if(result>=1e9) return -1;
    else return result;
    }
};