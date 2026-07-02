class Solution {
private:
    int solveRec(string &s, int i) {
        if (s.empty()) return 0;
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;

        int way1 = solveRec(s, i + 1);
        if (i + 1 < s.size() && stoi(s.substr(i, 2)) <= 26) way1 += solveRec(s, i + 2);

        return way1;
    }
    int solveMem(string &s, int i, vector<int>& dp){
        if(s.empty()) return 0;
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!= -1) return dp[i];

        int way1= solveMem(s, i+1, dp);
        if(i+1 < s.size() && stoi(s.substr(i,2)) <= 26) way1+= solveMem(s,i+2,dp);

        return dp[i]= way1;
    }
    
    int solveTab(string &s) {
    int n = s.size();
    if (n == 0) return 0;

    vector<int> dp(n + 1, -1);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') dp[i] = 0;
        else {
            int way1 = dp[i + 1];
            if (i + 1 < s.size() && stoi(s.substr(i, 2)) <= 26) way1 += dp[i + 2];
            dp[i] = way1;
        }
    }
    
    return dp[0];
}
public:
    int numDecodings(string s) {
        //vector<int> dp(s.size()+1, -1);
        return solveTab(s);
    }
};
